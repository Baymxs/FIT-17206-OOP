import java.io.*;

public class Main {
    public static void main(String[] args) {
        if (args.length != 2) throw new RuntimeException("invalid number of arguments");

        FileInputStream fileInputStream = null;

        try {
            fileInputStream = new FileInputStream(args[0]);
        } catch (FileNotFoundException e) {
            System.err.println("Error opening data file");
        }

        CSVCreator CSVCreator = null;
        try {
            CSVCreator = new CSVCreator(new Parser(fileInputStream), new UFileWriter(args[1]));
        } catch (IOException e) {
            System.out.println("error opening file");
        }

        try {
            if (CSVCreator != null) {
                CSVCreator.writeCSVData();
            }
        } catch (IOException | NullPointerException e) {
            System.err.println("Error writing CSV Data");
        }
    }
}
