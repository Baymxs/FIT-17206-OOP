import java.io.*;
import java.util.List;
import java.util.Map;

class CSVCreator {
    private String inputFileName;
    private String outputFileName;

    CSVCreator(String inputFileName, String outputFileName) {
        this.inputFileName = inputFileName;
        this.outputFileName = outputFileName;
    }

    void createCSVFile() {
        FileWriter fileWriter = null;
        try {
            fileWriter = new FileWriter(outputFileName);

            Parser parser = new Parser();

            List<Map.Entry<String, Integer>> CSVList = parser.getCSVData(inputFileName);

            for (Map.Entry<String, Integer> entry : parser.getCSVData(inputFileName)) {
                fileWriter.write(entry.getKey() + ";" + entry.getValue() + ";" + (float)entry.getValue()/parser.getWordCount() + "%" + "\n");
            }

            for (int i = CSVList.size() - 1; i >= 0; i--) {
                fileWriter.write(CSVList.get(i).getKey() + ";" + CSVList.get(i).getValue() + ";" + (float)CSVList.get(i).getValue()/parser.getWordCount() + "%" + "\n");
            }
        }
        catch (IOException e) {
            System.err.println("Error while writing to file: " + e.getLocalizedMessage());
        }
        finally {
            if (null != fileWriter) {
                try {
                    fileWriter.close();
                }
                catch (IOException e) {
                    e.printStackTrace(System.err);
                }
            }
        }
    }
}