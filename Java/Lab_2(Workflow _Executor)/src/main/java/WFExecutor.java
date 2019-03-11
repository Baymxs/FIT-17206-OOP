import BlocksFactory.Block;
import BlocksFactory.BlockFactory;
import Exceptions.BlockNotFoundException;
import org.apache.log4j.Logger;

import java.io.*;
import java.lang.reflect.InvocationTargetException;
import java.util.*;

public class WFExecutor {
    private static final Logger log = Logger.getLogger(WFExecutor.class);

    private InputStream inputStream;
    private Map<Integer, Block> blocks;
    private List<Integer> executionOrder;

    public WFExecutor(InputStream inputStream) {
        this.inputStream = inputStream;
        blocks = new HashMap<>();
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

        blocks.put(blockId, BlockFactory.getInstance().getBlock(blockName, blockArgsList));
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

    public void execute()
            throws NoSuchMethodException, BlockNotFoundException, IllegalAccessException, InstantiationException, InvocationTargetException, ClassNotFoundException, IOException {

        String text = "";

        readWorkflow();
        log.info("workflow file reading was successful");

        for (Integer i : executionOrder) {
            text = blocks.get(i).execute(text);
        }
    }
}
