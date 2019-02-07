import java.io.File;

public class Main {
    public static void main(String[] args) {
        if (args.length != 1) {
            throw new RuntimeException("invalid number of arguments");
        } else if (!args[0].equalsIgnoreCase("gui") & !args[0].equalsIgnoreCase("console")) {
            throw new RuntimeException("invalid game mode");
        }

        Minesweeper minesweeper = new Minesweeper(args[0]);
        minesweeper.start();
    }
}
