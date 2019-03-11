package BlocksFactory.Blocks;

import BlocksFactory.Block;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;

public class ReadFileBlock extends Block {
    public ReadFileBlock(List<String> arguments) {
        super(arguments);
    }

    @Override
    public String execute(String text) throws IOException {
        BufferedReader inputStream = null;

        String line;

        StringBuilder textBuilder = new StringBuilder();

        try {
            inputStream = new BufferedReader(new FileReader(getArgs().get(0)));

            while ((line = inputStream.readLine()) != null) {
                textBuilder.append(line);
                textBuilder.append("\n");
            }
        } finally {
            if (inputStream != null) {
                inputStream.close();
            }
        }
        return textBuilder.toString();
    }
}
