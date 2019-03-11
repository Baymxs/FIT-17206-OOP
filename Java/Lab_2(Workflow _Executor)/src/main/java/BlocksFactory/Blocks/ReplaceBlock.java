package BlocksFactory.Blocks;

import BlocksFactory.Block;

import java.util.List;

public class ReplaceBlock extends Block {
    public ReplaceBlock(List<String> arguments) {
        super(arguments);
    }

    @Override
    public String execute(String text) {
        return text.replaceAll(getArgs().get(0), getArgs().get(1));
    }
}