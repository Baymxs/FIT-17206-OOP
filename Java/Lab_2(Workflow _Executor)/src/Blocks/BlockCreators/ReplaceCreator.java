package Blocks.BlockCreators;

import Blocks.Block;
import Blocks.BlockCreator;
import Blocks.Blocks.ReplaceBlock;

import java.util.List;

public class ReplaceCreator implements BlockCreator {
    @Override
    public Block create(int blockId, String blockName, List<String> args) {
        return new ReplaceBlock(blockId, blockName, args);
    }
}
