import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class Parser {
    private BufferedReader bufferedReader;

    Parser(InputStream inputStream) {
        bufferedReader = new BufferedReader(new InputStreamReader(inputStream));
    }

    public String getWord() {
        boolean isCorrectValue = true;
        StringBuilder word = new StringBuilder();
        char value;

        while (isCorrectValue) {
            try {
                value = (char) bufferedReader.read();

                if (Character.isLetterOrDigit(value)) {
                    word.append(value);
                } else isCorrectValue = false;
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return word.toString();
    }
}
