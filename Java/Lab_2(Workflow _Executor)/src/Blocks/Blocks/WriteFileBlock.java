package Blocks.Blocks;

import Blocks.Block;
import Blocks.BlockCreators.WriteFileCreator;
import Blocks.BlockFactory;

import java.io.*;
import java.util.List;

public class WriteFileBlock extends Block {
    static {
        BlockFactory.getInstance().registerBlock("WriteFile", new WriteFileCreator());
    }

    public WriteFileBlock(int id, String name, List<String> arguments) {
        super(id, name, arguments);
    }

    @Override
    public StringBuilder execute(StringBuilder text) {
        BufferedWriter outputStream = null;
        try {
            outputStream = new BufferedWriter(new FileWriter(getArgs().get(0)));

            outputStream.write(text.toString());
        } catch (IOException e) {
            System.out.println("I/O error: " + e);
        } finally {
            try {
                if (outputStream != null) {
                    outputStream.close();
                }
            } catch (IOException e) {
                System.out.println("error opening file");
            }
        }
        return null;
    }
}
