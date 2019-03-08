package BlocksFactory.Blocks;

import BlocksFactory.Block;

import java.util.List;

public class ReplaceBlock extends Block {
    public ReplaceBlock(int id, String name, List<String> arguments) {
        super(id, name, arguments);
    }

    @Override
    public StringBuilder execute(StringBuilder text) {
        String replacedText = text.toString().replaceAll(getArgs().get(0), getArgs().get(1));

        text.setLength(0);

        text.append(replacedText);

        return text;
    }
}