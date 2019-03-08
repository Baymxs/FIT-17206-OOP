package BlocksFactory;

import java.util.List;

public abstract class Block {
    private int id;
    private String name;
    private List<String> arguments;

    public Block(int id, String name, List<String> arguments) {
        this.id = id;
        this.name = name;
        this.arguments = arguments;
    }

    public int getId() {
        return id;
    }

    public List<String> getArgs() {
        return arguments;
    }

    public abstract StringBuilder execute(StringBuilder text);
}
