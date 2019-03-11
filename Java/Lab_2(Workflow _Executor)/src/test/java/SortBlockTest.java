import BlocksFactory.Blocks.SortBlock;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.*;

public class SortBlockTest {

    @Test
    public void execute() {
        List<String> arguments = new ArrayList<>();

        String text = "Hello, Jessica!\nDid you see Susan?\nNo, I didn't.\nSo, Jessica, let's go to the club tonight?\nDon't tell about this to Susan.";

        SortBlock sortBlock = new SortBlock(arguments);

        assertEquals(sortBlock.execute(text), "Did you see Susan?\nDon't tell about this to Susan.\nHello, Jessica!\nNo, I didn't.\nSo, Jessica, let's go to the club tonight?");
    }
}