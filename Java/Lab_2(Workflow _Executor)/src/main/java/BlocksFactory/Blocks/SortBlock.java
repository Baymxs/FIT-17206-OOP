package BlocksFactory.Blocks;

import BlocksFactory.Block;

import java.util.Arrays;
import java.util.List;

public class SortBlock extends Block {
    public SortBlock(List<String> arguments) {
        super(arguments);
    }

    @Override
    public String execute(String text) {
        StringBuilder textBuilder = new StringBuilder();

        String[] lines = text.split("\n");

        Arrays.sort(lines);

        for (int i = 0; i < lines.length ; i++) {
            textBuilder.append(lines[i]);
            if (i != lines.length -1) {
                textBuilder.append("\n");
            }
        }

        return textBuilder.toString();
    }
}
