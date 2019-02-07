import java.io.*;
import java.util.List;
import java.util.Map;

class CSVCreator implements WriteFile{
    private String inputFileName;
    private String outputFileName;


    CSVCreator(String inputFileName, String outputFileName) {
        this.inputFileName = inputFileName;
        this.outputFileName = outputFileName;
    }

    @Override
    public void writeFile(StringBuilder text) {
        FileWriter fileWriter = null;

        try {
            fileWriter = new FileWriter(outputFileName);
            fileWriter.write(text.toString());
        } catch (IOException e) {
            System.err.println("Error while writing to file: " + e.getLocalizedMessage());
        } finally {
            if (null != fileWriter) {
                try {
                    fileWriter.close();
                } catch (IOException e) {
                    e.printStackTrace(System.err);
                }
            }
        }
    }

    void createCSVFile() {
        StringBuilder stringBuilder = new StringBuilder();

        Parser parser = new Parser();
        List<Map.Entry<String, Integer>> CSVList = parser.getCSVData(inputFileName);

        for (int i = CSVList.size() - 1; i >= 0; i--) {
            stringBuilder.append(CSVList.get(i).getKey());
            stringBuilder.append(";");
            stringBuilder.append(CSVList.get(i).getValue());
            stringBuilder.append((float)CSVList.get(i).getValue()/parser.getWordCount());
            stringBuilder.append("%");
            stringBuilder.append("\n");
        }

        writeFile(stringBuilder);
    }
}