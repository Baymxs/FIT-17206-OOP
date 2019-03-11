package BlocksFactory.Blocks;

import BlocksFactory.Block;

import java.util.List;

public class GrepBlock extends Block {
    public GrepBlock(List<String> arguments) {
        super(arguments);
    }

    @Override
    public String execute(String text) {
        StringBuilder textBuilder = new StringBuilder();

        String[] lines = text.split("\n");
        //to make lines again
        for (int i = 0; i < lines.length - 1; i++) {
            lines[i] = lines[i] + "\n";
        }

        for (String line : lines) {
            if (line.contains(getArgs().get(0))) {
                textBuilder.append(line);
            }
        }

        return textBuilder.toString();
    }
}
