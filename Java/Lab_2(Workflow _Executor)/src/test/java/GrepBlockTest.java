import BlocksFactory.Blocks.GrepBlock;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.*;

public class GrepBlockTest {

    @Test
    public void execute() {
        List<String> arguments = new ArrayList<>();
        arguments.add("Jessica");

        String text = "Hello, Jessica!\nDid you see Susan?\nNo, I didn't.\nSo, Jessica, let's go to the club tonight?\nDon't tell about this to Susan.";

        GrepBlock grepBlock = new GrepBlock(arguments);

        assertEquals(grepBlock.execute(text), "Hello, Jessica!\nSo, Jessica, let's go to the club tonight?");
    }
}