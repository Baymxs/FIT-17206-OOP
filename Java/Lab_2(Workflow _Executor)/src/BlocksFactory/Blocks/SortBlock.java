package BlocksFactory.Blocks;

import BlocksFactory.Block;

import java.util.Arrays;
import java.util.List;

public class SortBlock extends Block {
    public SortBlock(int id, String name, List<String> arguments) {
        super(id, name, arguments);
    }

    @Override
    public StringBuilder execute(StringBuilder text) {
        String[] lines = text.toString().split("\n");

        Arrays.sort(lines);

        text.setLength(0);

        for (String line : lines) {
            text.append(line);
        }

        return text;
    }
}
