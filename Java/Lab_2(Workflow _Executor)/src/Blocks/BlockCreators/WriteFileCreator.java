package Blocks.BlockCreators;

import Blocks.Block;
import Blocks.BlockCreator;
import Blocks.Blocks.WriteFileBlock;

import java.util.List;

public class WriteFileCreator implements BlockCreator {
    @Override
    public Block create(int blockId, String blockName, List<String> args) {
        return new WriteFileBlock(blockId, blockName, args);
    }
}
