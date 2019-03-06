package Blocks.Blocks;

import Blocks.Block;
import Blocks.BlockCreators.SortCreator;
import Blocks.BlockFactory;

import java.util.Arrays;
import java.util.List;

public class SortBlock extends Block {
    static {
        BlockFactory.getInstance().registerBlock("Sort", new SortCreator());
    }

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
