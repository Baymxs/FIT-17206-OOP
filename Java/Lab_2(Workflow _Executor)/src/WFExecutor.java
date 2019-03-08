import BlocksFactory.Block;
import BlocksFactory.BlockFactory;
import Exceptions.BlockNotFoundException;

import java.io.*;
import java.lang.reflect.InvocationTargetException;
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

    private void parseBlock(String line)
            throws IOException, NoSuchMethodException, BlockNotFoundException, IllegalAccessException, InstantiationException, InvocationTargetException, ClassNotFoundException
    {
        int blockId;
        String blockName;
        List<String> blockArgsList = null;

        String[] parsedBlockLine = line.split(" = ", 2);

        blockId = Integer.parseInt(parsedBlockLine[0]);
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

    private void readWorkflow()
            throws NoSuchMethodException, BlockNotFoundException, IllegalAccessException, InstantiationException, InvocationTargetException, ClassNotFoundException, IOException {

        BufferedReader bufferedReader = null;

        boolean blocks_parsing = false, execute_order_parsing = false;
        String line;

        try {
            bufferedReader = new BufferedReader(new InputStreamReader(inputStream));

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
        } finally {
            if (inputStream != null) {
                inputStream.close();
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

    public void execute()
            throws NoSuchMethodException, BlockNotFoundException, IllegalAccessException, InstantiationException, InvocationTargetException, ClassNotFoundException, IOException {

        StringBuilder text = new StringBuilder();
        Block block;

        readWorkflow();

        for (Integer i : executionOrder) {
            block = findBlockById(i);
            block.execute(text);
        }
    }
}
