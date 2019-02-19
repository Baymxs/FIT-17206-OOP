import java.io.IOException;
import java.util.ArrayList;

public interface StreamWriter {
    void write(ArrayList<String> CSVLine) throws IOException;
}
