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
        blocksProperties.load(BlockFactory.class.getResourceAsStream("blocks.properties"));
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

    public Block getBlock(int blockId, String blockName, List<String> args)
            throws BlockNotFoundException, ClassNotFoundException, NoSuchMethodException, IllegalAccessException, InvocationTargetException, InstantiationException
    {
        if (!blocksProperties.containsKey(blockName)) {
            throw new BlockNotFoundException("Block " + blockName + " not found");
        }
        return (Block) Class.forName("BlocksFactory.Blocks." + blocksProperties.get(blockName)).getConstructor(new Class[]{int.class, String.class, List.class}).newInstance(blockId, blockName, args);
    }
}
