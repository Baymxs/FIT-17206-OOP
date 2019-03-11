package BlocksFactory.Blocks;

import BlocksFactory.Block;

import java.io.*;
import java.util.List;

public class WriteFileBlock extends Block {
    public WriteFileBlock(List<String> arguments) {
        super(arguments);
    }

    @Override
    public String execute(String text) throws IOException {
        BufferedWriter outputStream = null;
        try {
            outputStream = new BufferedWriter(new FileWriter(getArgs().get(0)));

            outputStream.write(text);
        } finally {
            if (outputStream != null) {
                outputStream.close();
            }
        }
        return null;
    }
}
