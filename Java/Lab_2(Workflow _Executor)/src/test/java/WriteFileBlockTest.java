import BlocksFactory.Blocks.ReadFileBlock;
import BlocksFactory.Blocks.WriteFileBlock;
import org.junit.Test;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.*;

public class WriteFileBlockTest {

    @Test
    public void execute() throws IOException {
        List<String> arguments = new ArrayList<>();
        arguments.add("output.txt");

        WriteFileBlock writeFileBlock = new WriteFileBlock(arguments);
        writeFileBlock.execute("Hello, Jessica!\nDid you see Susan?\nNo, I didn't.\nSo, Jessica, let's go to the club tonight?\nDon't tell about this to Susan.\n");

        BufferedReader inputStream = null;

        String line;

        StringBuilder textBuilder = new StringBuilder();

        try {
            inputStream = new BufferedReader(new FileReader("output.txt"));

            while ((line = inputStream.readLine()) != null) {
                textBuilder.append(line);
                textBuilder.append("\n");
            }
        } finally {
            if (inputStream != null) {
                inputStream.close();
            }
        }

        assertEquals(textBuilder.toString(), "Hello, Jessica!\nDid you see Susan?\nNo, I didn't.\nSo, Jessica, let's go to the club tonight?\nDon't tell about this to Susan.\n");
    }
}