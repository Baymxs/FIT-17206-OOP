import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class UFileWriter implements StreamWriter {
    private FileWriter fileWriter;
    private String separator;

    UFileWriter(String fileName) {
        try {
            fileWriter = new FileWriter(fileName);
        } catch (IOException e) {
            System.out.println("error opening file");
        }
        separator = ",";
    }

    @Override
    public void write(ArrayList<String> CSVLine) throws IOException {
        fileWriter.write(CSVLine.get(0) + separator + CSVLine.get(1) + separator + CSVLine.get(2) + "\n");
    }
}
