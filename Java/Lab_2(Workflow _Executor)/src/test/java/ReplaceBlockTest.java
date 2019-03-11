import BlocksFactory.Blocks.ReplaceBlock;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.*;

public class ReplaceBlockTest {

    @Test
    public void execute() {
        List<String> arguments = new ArrayList<>();
        arguments.add("Susan");
        arguments.add("Betty");

        String text = "Hello, Jessica!\nDid you see Susan?\nNo, I didn't.\nSo, Jessica, let's go to the club tonight?\nDon't tell about this to Susan.";

        ReplaceBlock replaceBlock = new ReplaceBlock(arguments);

        assertEquals(replaceBlock.execute(text), "Hello, Jessica!\nDid you see Betty?\nNo, I didn't.\nSo, Jessica, let's go to the club tonight?\nDon't tell about this to Betty.");
    }
}