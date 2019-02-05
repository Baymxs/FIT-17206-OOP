import java.util.Map;

class WordCount {
    private String _fileName;

    WordCount(String[] args) {
        if (args.length != 1 ) throw new RuntimeException("invalid number of arguments");
        _fileName  = args[0];
    }

    void createCSVFile() {
        Parser parser = new Parser();

        for (Map.Entry<String, Integer> entry : parser.getCSVData(_fileName)) {
            System.out.println(entry.getKey() + ";" + entry.getValue() + ";" + (float)entry.getValue()/parser.getWordCount() + "%");
        }

    }
}
