package ViewFactory;

import java.io.File;
import java.util.Map;
import java.util.TreeMap;

public class ViewFactory {
    private static ViewFactory viewFactory;

    private Map<String, ViewCreator> views;

    private ViewFactory() {
        views = new TreeMap<>(String.CASE_INSENSITIVE_ORDER);
    }

    private static void registerViews() {
        File directory = new File("src/ViewFactory/Views");

        String[] classNames = directory.list();
        try {
            for (String className : classNames) {
                String fullClassName = className.split(".java")[0];
                try {
                    Class.forName("ViewFactory.Views." + fullClassName);
                } catch (ClassNotFoundException e) {
                    e.printStackTrace();
                }
            }
        }catch (NullPointerException ex) {
            System.out.println("No view support");
            ex.printStackTrace();
        }
    }

    public static ViewFactory getInstance() {
        if (viewFactory == null) {
            viewFactory = new ViewFactory();
            registerViews();
        }
        return viewFactory;
    }

    public View getView(String gameMode) {
        return views.get(gameMode).create();
    }

    public void registerView(String gameMode, ViewCreator creator) {
        if (views.containsKey(gameMode)) {
            if (views.get(gameMode) == creator) return;
            views.remove(gameMode);
        }
        views.put(gameMode, creator);
    }
}
