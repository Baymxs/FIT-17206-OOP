import Exceptions.ProgramArgException;

import java.io.FileInputStream;
import java.io.InputStream;

public class Main {
    public static void main(String[] args) throws ProgramArgException {
        if (args.length != 1) {
            throw new ProgramArgException("invalid number of program arguments");
        }

        try {
            InputStream inputStream = new FileInputStream(args[0]);

            WFExecutor wfExecutor = new WFExecutor(inputStream);
            wfExecutor.execute();
        } catch (Exception e) {
            System.err.println("Error: " + e);
        }
    }
}
