package Blocks;

import java.io.File;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

public class BlockFactory {
    private static volatile BlockFactory blockFactory;

    private Map<String, BlockCreator> blocks;

    private BlockFactory() {
        blocks = new TreeMap<>(String.CASE_INSENSITIVE_ORDER);
    }

    private static void registerBlocks() {
        File directory = new File("src/Blocks/Blocks");

        String[] classNames = directory.list();
        try {
            for (String className : classNames) {
                String fullClassName = className.split(".java")[0];
                try {
                    Class.forName("Blocks.Blocks." + fullClassName);
                } catch (ClassNotFoundException e) {
                    e.printStackTrace();
                }
            }
        } catch (NullPointerException ex) {
            System.out.println("No blocks found");
            ex.printStackTrace();
        }
    }

    public static BlockFactory getInstance() {
        //Double-check with synchronized block for thread saving
        if (blockFactory == null) {
            synchronized (BlockFactory.class) {
                if (blockFactory == null) {
                    blockFactory = new BlockFactory();
                    registerBlocks();
                }
            }
        }
        return blockFactory;
    }

    public Block getBlock(int blockId, String blockName, List<String> args) {
        return blocks.get(blockName).create(blockId, blockName, args);
    }

    public void registerBlock(String blockName, BlockCreator creator) {
        if (blocks.containsKey(blockName)) {
            if (blocks.get(blockName) == creator) return;
            blocks.remove(blockName);
        }
        blocks.put(blockName, creator);
    }
}
