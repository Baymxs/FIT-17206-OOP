package Blocks.BlockCreators;

import Blocks.Block;
import Blocks.BlockCreator;
import Blocks.Blocks.SortBlock;

import java.util.List;

public class SortCreator implements BlockCreator {
    @Override
    public Block create(int blockId, String blockName, List<String> args) {
        return new SortBlock(blockId, blockName, args);
    }
}
