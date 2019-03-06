import Blocks.Block;
import Blocks.BlockFactory;
import Exceptions.IncorrectWorkflowException;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class WFExecutor {
    private InputStream inputStream;
    private List<Block> blocks;
    private List<Integer> executionOrder;

    public WFExecutor(InputStream inputStream) {
        this.inputStream = inputStream;
        blocks = new ArrayList<>();
        executionOrder = new ArrayList<>();
    }

    public void checkWorkflow() throws IncorrectWorkflowException {

    }

    private void parseBlock(String line) {
        int blockId;
        String blockName;
        List<String> blockArgsList = null;

        String[] parsedBlockLine = line.split(" = ", 2);

        blockId = Integer.parseInt(parsedBlockLine[0]);
        System.out.println(parsedBlockLine[1]);
        String[] parsedNameAndArgs = parsedBlockLine[1].split(" ", 2);
        blockName = parsedNameAndArgs[0];

        if (parsedNameAndArgs.length != 1) {
            blockArgsList = Arrays.asList(parsedNameAndArgs[1].split(" "));
        }

        blocks.add(BlockFactory.getInstance().getBlock(blockId, blockName, blockArgsList));
    }

    private void parseExecutionOrder(String line) {
        for (String s : line.split(" -> ")) {
            executionOrder.add(Integer.parseInt(s));
        }
    }

    private void readWorkflow() throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inputStream));

        boolean blocks_parsing = false, execute_order_parsing = false;
        String line;

        while ((line = bufferedReader.readLine()) != null) {
            if (line.equals("desc")) {
                blocks_parsing = true;
            } else if (line.equals("csed")) {
                blocks_parsing = false;
                execute_order_parsing = true;
            } else if (blocks_parsing) {
                parseBlock(line);
            } else if (execute_order_parsing) {
                parseExecutionOrder(line);
            }
        }
    }

    private Block findBlockById(int blockId) {
        Block block = null;
        for (Block b : blocks) {
            if (b.getId() == blockId) {
                block = b;
            }
        }
        return block;
    }

    public void execute() throws IOException, IncorrectWorkflowException {
        checkWorkflow();
        StringBuilder text = new StringBuilder();
        Block block;

        readWorkflow();

        for (Integer i : executionOrder) {
            block = findBlockById(i);
            block.execute(text);
        }
    }
}
