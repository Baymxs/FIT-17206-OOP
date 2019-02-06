public class Main {
    public static void main(String[] args) {
        if (args.length != 1 && args.length != 2 ) throw new RuntimeException("invalid number of arguments");

        CSVCreator CSVCreator = new CSVCreator(args[0], args[1]);
        CSVCreator.createCSVFile();
    }
}