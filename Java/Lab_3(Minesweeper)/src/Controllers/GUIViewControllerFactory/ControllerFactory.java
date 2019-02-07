package Controllers.GUIViewControllerFactory;

import java.io.File;
import java.util.Map;
import java.util.TreeMap;

public class ControllerFactory {
    private static ControllerFactory controllerFactory;

    private Map<String, ControllerCreator> controllers;

    private ControllerFactory() {
        controllers = new TreeMap<>(String.CASE_INSENSITIVE_ORDER);
    }

    private static void registerControllers() {
        File directory = new File("src/Controllers/GUIViewControllerFactory/Controllers");

        String[] classNames = directory.list();
        try {
            for (String className : classNames) {
                String fullClassName = className.split(".java")[0];
                try {
                    Class.forName("Controllers.GUIViewControllerFactory.Controllers." + fullClassName);
                } catch (ClassNotFoundException e) {
                    e.printStackTrace();
                }
            }
        }catch (NullPointerException ex) {
            System.out.println("No controller support");
            ex.printStackTrace();
        }
    }

    public static ControllerFactory getInstance() {
        if (controllerFactory == null) {
            controllerFactory = new ControllerFactory();
            registerControllers();
        }
        return controllerFactory;
    }

    public Controller getController(String gameStage) {
        return controllers.get(gameStage).create();
    }

    public void registerController(String gameStage, ControllerCreator creator) {
        if (controllers.containsKey(gameStage)) {
            if (controllers.get(gameStage) == creator) return;
            controllers.remove(gameStage);
        }
        controllers.put(gameStage, creator);
    }
}
