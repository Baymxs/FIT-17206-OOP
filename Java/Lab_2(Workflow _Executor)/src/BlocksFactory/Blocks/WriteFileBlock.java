package BlocksFactory.Blocks;

import BlocksFactory.Block;

import java.io.*;
import java.util.List;

public class WriteFileBlock extends Block {
    public WriteFileBlock(int id, String name, List<String> arguments) {
        super(id, name, arguments);
    }

    @Override
    public StringBuilder execute(StringBuilder text) throws IOException {
        BufferedWriter outputStream = null;
        try {
            outputStream = new BufferedWriter(new FileWriter(getArgs().get(0)));

            outputStream.write(text.toString());
        } finally {
            if (outputStream != null) {
                outputStream.close();
            }
        }
        return null;
    }
}
