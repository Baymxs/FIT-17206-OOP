import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class Parser {
    private BufferedReader bufferedReader;

    Parser(InputStream inputStream) {
        bufferedReader = new BufferedReader(new InputStreamReader(inputStream));
    }

    public int getWord(StringBuilder word) throws IOException {
        boolean isCorrectValue = true;
        int value = -1;

        while (isCorrectValue) {
            value = bufferedReader.read();

            if (Character.isLetterOrDigit((char)value)) {
                word.append((char) value);
            } else {
                isCorrectValue = false;
            }
        }
        return value;
    }
}
