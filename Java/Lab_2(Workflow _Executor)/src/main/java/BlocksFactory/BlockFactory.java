package BlocksFactory;

import Exceptions.BlockNotFoundException;

import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.util.List;
import java.util.Properties;

public class BlockFactory {
    private static volatile BlockFactory blockFactory;
    private Properties blocksProperties = new Properties();


    private BlockFactory() throws IOException {
        blocksProperties.load(BlockFactory.class.getClassLoader().getResourceAsStream("blocks.properties"));
    }

    public static BlockFactory getInstance() throws IOException {
        //Double-check with synchronized block for thread saving
        if (blockFactory == null) {
            synchronized (BlockFactory.class) {
                if (blockFactory == null) {
                    blockFactory = new BlockFactory();
                }
            }
        }
        return blockFactory;
    }

    public Block getBlock(String blockName, List<String> args)
            throws BlockNotFoundException, ClassNotFoundException, NoSuchMethodException, IllegalAccessException, InvocationTargetException, InstantiationException, IOException {

        Properties config = new Properties();
        config.load(BlockFactory.class.getClassLoader().getResourceAsStream("config.properties"));

        if (!blocksProperties.containsKey(blockName)) {
            throw new BlockNotFoundException("Block " + blockName + " not found");
        }
        return (Block) Class.forName(config.getProperty("BLOCK_CLASS_PATH") + blocksProperties.get(blockName)).getConstructor(new Class[]{List.class}).newInstance(args);
    }
}
