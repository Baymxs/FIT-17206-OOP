package Blocks;

import java.util.List;

public interface BlockCreator {
    Block create(int blockId, String blockName, List<String> args);
}
