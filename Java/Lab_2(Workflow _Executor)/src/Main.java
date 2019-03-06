import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

public class Main {
    public static void main(String[] args) {
        if (args.length != 1) {
            throw new RuntimeException("invalid number of arguments");
        }

        try {
            InputStream inputStream = new FileInputStream(args[0]);

            WFExecutor wfExecutor = new WFExecutor(inputStream);
            wfExecutor.execute();
        } catch (IOException ex) {
            System.err.println("error opening file");
            ex.printStackTrace();
        }
    }
}
