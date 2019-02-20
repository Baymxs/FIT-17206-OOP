import java.io.IOException;
import java.util.List;

public interface StreamWriter {
    void write(List<String> CSVLine) throws IOException;
}
