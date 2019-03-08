package BlocksFactory.Blocks;

import BlocksFactory.Block;

import java.util.List;

public class GrepBlock extends Block {
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
