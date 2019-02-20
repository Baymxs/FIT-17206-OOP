import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class UFileWriter implements StreamWriter {
    private FileWriter fileWriter;
    private String separator;

    UFileWriter(String fileName) throws IOException{
        fileWriter = new FileWriter(fileName);
        separator = ",";
    }

    @Override
    public void write(List<String> CSVLine) throws IOException {
        String result_CSV_line = String.join(separator, CSVLine);
        fileWriter.write(result_CSV_line + "\n");
    }
}
