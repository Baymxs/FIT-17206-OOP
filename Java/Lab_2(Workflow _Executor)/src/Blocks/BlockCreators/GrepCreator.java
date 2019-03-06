package Blocks.BlockCreators;

import Blocks.Block;
import Blocks.BlockCreator;
import Blocks.Blocks.GrepBlock;

import java.util.List;

public class GrepCreator implements BlockCreator {
    @Override
    public Block create(int blockId, String blockName, List<String> args) {
        return new GrepBlock(blockId, blockName, args);
    }
}
