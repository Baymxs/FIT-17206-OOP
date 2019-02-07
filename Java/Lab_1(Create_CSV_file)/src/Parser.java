import java.io.*;
import java.util.*;

public class Parser implements ReadFile{
    private Map<String, Integer> _CSV_map;
    private int _word_count;

    Parser() {
        _CSV_map = new HashMap<>();
        _word_count = 0;
    }

    int getWordCount() {
        return _word_count;
    }

    @Override
    public StringBuilder readFile(String fileName) {
        BufferedReader reader = null;
        final StringBuilder fileData = new StringBuilder();

        try {
            reader = new BufferedReader(new InputStreamReader(new FileInputStream(fileName)));

            String line;
            while ((line=reader.readLine())!=null) {
                fileData.append(line);
            }
        }
        catch (IOException e) {
            System.err.println("Error while reading file: " + e.getLocalizedMessage());
        }
        finally {
            if (null != reader) {
                try {
                    reader.close();
                }
                catch (IOException e) {
                    e.printStackTrace(System.err);
                }
            }
        }
        return fileData;
    }

    List<Map.Entry<String, Integer>> getCSVData(String fileName) {
        parseFile(readFile(fileName));

        List<Map.Entry<String, Integer>> list = new ArrayList<>(_CSV_map.entrySet());
        list.sort(Map.Entry.comparingByValue());

        return list;
    }

    void parseFile(StringBuilder fileData) {
        StringBuilder word = new StringBuilder();

        for (char smb : fileData.toString().toCharArray()) {
            if (Character.isLetterOrDigit(smb)) {
                word.append(smb);
            } else if (word.length() > 0) {
                if (!_CSV_map.containsKey(word.toString())) {
                    _CSV_map.put(word.toString(), 1);
                    _word_count++;
                } else {
                    _CSV_map.replace(word.toString(), (_CSV_map.get(word.toString()) + 1));
                }
                word.setLength(0);
            }
        }
    }
}
