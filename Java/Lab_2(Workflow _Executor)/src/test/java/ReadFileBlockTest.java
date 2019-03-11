import BlocksFactory.Blocks.ReadFileBlock;
import org.junit.Test;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.*;

public class ReadFileBlockTest {

    @Test
    public void execute() throws IOException {
        List<String> arguments = new ArrayList<>();
        arguments.add("input.txt");

        ReadFileBlock readFileBlock = new ReadFileBlock(arguments);

        assertEquals(readFileBlock.execute(""), "Hello, Jessica!\nDid you see Susan?\nNo, I didn't.\nSo, Jessica, let's go to the club tonight?\nDon't tell about this to Susan.\n");
    }
}