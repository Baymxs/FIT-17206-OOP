package Blocks.Blocks;

import Blocks.Block;
import Blocks.BlockCreators.GrepCreator;
import Blocks.BlockFactory;

import java.util.List;

public class GrepBlock extends Block {
    static {
        BlockFactory.getInstance().registerBlock("Grep", new GrepCreator());
    }

    public GrepBlock(int id, String name, List<String> arguments) {
        super(id, name, arguments);
    }

    @Override
    public StringBuilder execute(StringBuilder text) {
        String[] lines = text.toString().split("\n");

        text.setLength(0);

        for (String line : lines) {
            if (line.contains(getArgs().get(0))) {
                text.append(line);
            }
        }

        return text;
    }
}
