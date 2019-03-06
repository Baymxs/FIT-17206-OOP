package Blocks.BlockCreators;

import Blocks.Block;
import Blocks.BlockCreator;
import Blocks.Blocks.ReadFileBlock;

import java.util.List;

public class ReadFileCreator implements BlockCreator {
    @Override
    public Block create(int blockId, String blockName, List<String> args) {
        return new ReadFileBlock(blockId, blockName, args);
    }
}
