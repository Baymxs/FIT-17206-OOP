package BlocksFactory.Blocks;

import BlocksFactory.Block;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;

public class ReadFileBlock extends Block {
    public ReadFileBlock(int id, String name, List<String> arguments) {
        super(id, name, arguments);
    }

    @Override
    public StringBuilder execute(StringBuilder text) {
        BufferedReader inputStream = null;

        String line;

        try {
            inputStream = new BufferedReader(new FileReader(getArgs().get(0)));

            while ((line = inputStream.readLine()) != null) {
                text.append(line);
                text.append("\n");
            }
        } catch (IOException e) {
            System.out.println("I/O error: " + e);
        } finally {
            try {
                if (inputStream != null) {
                    inputStream.close();
                }
            } catch (IOException e) {
                System.out.println("error closing file");
            }
        }
        return text;
    }
}
