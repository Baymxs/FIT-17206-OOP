import Exceptions.ProgramArgException;

import java.io.FileInputStream;
import java.io.InputStream;

import org.apache.log4j.Logger;

public class Main {
    private static final Logger log = Logger.getLogger(Main.class);

    public static void main(String[] args) throws ProgramArgException {
        if (args.length != 1) {
            try {
                throw new ProgramArgException("invalid number of program arguments");
            } catch (ProgramArgException e) {
                log.error(e);
                return;
            }
        }

        try {
            InputStream inputStream = new FileInputStream(args[0]);

            WFExecutor wfExecutor = new WFExecutor(inputStream);
            log.info("execution start");
            wfExecutor.execute();
            log.info("execution was successful");
        } catch (Exception e) {
            log.error(e);
        }
    }
}
