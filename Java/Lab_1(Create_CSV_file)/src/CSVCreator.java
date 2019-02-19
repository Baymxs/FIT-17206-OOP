import java.io.IOException;
import java.lang.reflect.Array;
import java.util.*;

class CSVCreator {
    private StreamWriter streamWriter;
    private Parser parser;
    private Map<String, Integer> CSVMap;
    private int wordCount;

    CSVCreator(Parser parser, StreamWriter streamWriter) {
        this.parser = parser;
        this.streamWriter = streamWriter;
        CSVMap = new HashMap<>();
        wordCount = 0;
    }

    private List<Map.Entry<String, Integer>> createCSVData() {
        StringBuilder word = new StringBuilder();
        while (true) {
            try {
                if ((parser.getWord(word) == -1)) break;
            } catch (IOException e) {
                System.out.println("data reading error");
            }
            if (word.length() != 0) {
                if (CSVMap.containsKey(word.toString())) {
                    CSVMap.put(word.toString(), CSVMap.get(word.toString()) + 1);
                } else {
                    CSVMap.put(word.toString(), 1);
                }
                wordCount++;
                word.delete(0, word.length());
            }
        }

        List<Map.Entry<String, Integer>> CSVList = new ArrayList<>(CSVMap.entrySet());
        CSVList.sort(Map.Entry.comparingByValue());

        return CSVList;
    }

    public void writeCSVData() {
        List<Map.Entry<String, Integer>> CSVList = createCSVData();

        ArrayList<String> CSVLine = new ArrayList<>();

        for (int i = CSVList.size() - 1; i >= 0; i--) {
            CSVLine.add(CSVList.get(i).getKey());
            CSVLine.add(CSVList.get(i).getValue() + "");
            CSVLine.add(((float)CSVList.get(i).getValue()/wordCount)*100 + "");

            try {
                streamWriter.write(CSVLine);
            } catch (IOException e) {
                System.err.println("error writing CSV Data");
            }

            CSVLine.clear();
        }
    }
}