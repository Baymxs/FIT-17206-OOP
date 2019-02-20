import java.io.IOException;
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

    private List<Map.Entry<String, Integer>> createCSVData() throws IOException  {
        StringBuilder word = new StringBuilder();
        while ((parser.getWord(word) != -1)) {
            System.out.println("data reading error");
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

    public void writeCSVData() throws IOException{
        List<Map.Entry<String, Integer>> CSVList = createCSVData();

        ArrayList<String> CSVLine = new ArrayList<>();

        for (int i = CSVList.size() - 1; i >= 0; i--) {
            CSVLine.add(CSVList.get(i).getKey());
            CSVLine.add(CSVList.get(i).getValue() + "");
            CSVLine.add(((float)CSVList.get(i).getValue()/wordCount)*100 + "");

            streamWriter.write(CSVLine);

            CSVLine.clear();
        }
    }
}