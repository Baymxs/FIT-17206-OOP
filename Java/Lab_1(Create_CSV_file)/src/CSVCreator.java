import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

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
        String word;
        while (!(word = parser.getWord()).equals("")) {
            if (CSVMap.containsKey(word)) {
                CSVMap.put(word, CSVMap.get(word) + 1);
            } else {
                CSVMap.put(word, 1);
            }
            wordCount++;
        }

        List<Map.Entry<String, Integer>> CSVList = new ArrayList<>(CSVMap.entrySet());
        CSVList.sort(Map.Entry.comparingByValue());

        return CSVList;
    }

    public void printCSVData() {
        List<Map.Entry<String, Integer>> CSVList = createCSVData();
        StringBuilder CSVData = new StringBuilder();


        for (int i = CSVList.size() - 1; i >= 0; i--) {
            CSVData.append(CSVList.get(i).getKey());
            CSVData.append(",");
            CSVData.append(CSVList.get(i).getValue());
            CSVData.append(",");
            float percent = (float)CSVList.get(i).getValue()/wordCount * 100;
            CSVData.append(percent);
            CSVData.append("\n");
        }

        streamWriter.write(CSVData);
    }
}