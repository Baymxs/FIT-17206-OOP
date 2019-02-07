package Controllers.GUIViewControllerFactory.ControllerCreators;

import Controllers.GUIViewControllerFactory.Controller;
import Controllers.GUIViewControllerFactory.ControllerCreator;
import Controllers.GUIViewControllerFactory.Controllers.MenuController;

public class MenuControllerCreator implements ControllerCreator {
    @Override
    public Controller create() {
        return new MenuController();
    }
}
