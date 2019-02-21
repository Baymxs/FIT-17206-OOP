import java.io.*;

public class Main {
    public static void main(String[] args) {
        if (args.length != 2) throw new RuntimeException("invalid number of arguments");

        FileInputStream fileInputStream = null;

        try {
            fileInputStream = new FileInputStream("wqerr");

            CSVCreator CSVCreator = new CSVCreator(new Parser(fileInputStream), new UFileWriter(args[1]));
            CSVCreator.writeCSVData();
        } catch (IOException e) {
            e.printStackTrace();
            System.err.println("Error creating CSV Data: " + e);
        }
    }
}
