package BlocksFactory;

import java.io.IOException;
import java.util.List;

public abstract class Block {
    private List<String> arguments;

    public Block(List<String> arguments) {
        this.arguments = arguments;
    }

    public List<String> getArgs() {
        return arguments;
    }

    public abstract String execute(String text) throws IOException;
}
