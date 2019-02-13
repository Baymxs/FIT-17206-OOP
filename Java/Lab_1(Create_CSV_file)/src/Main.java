import java.io.*;

public class Main {
    public static void main(String[] args) {
        if (args.length != 2) throw new RuntimeException("invalid number of arguments");

        FileInputStream fileInputStream = null;
        try {
            fileInputStream = new FileInputStream(args[0]);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        CSVCreator CSVCreator = new CSVCreator(new Parser(fileInputStream), CSVData -> {
            FileWriter fileWriter = null;
            try {
                fileWriter = new FileWriter(args[1]);
                fileWriter.write(CSVData.toString());
            } catch (IOException e) {
                System.err.println("Error while writing to file: " + e.getLocalizedMessage());
            } finally {
                if (null != fileWriter) {
                    try {
                        fileWriter.close();
                    } catch (IOException e) {
                        e.printStackTrace(System.err);
                    }
                }
            }
        });

        CSVCreator.printCSVData();
    }
}