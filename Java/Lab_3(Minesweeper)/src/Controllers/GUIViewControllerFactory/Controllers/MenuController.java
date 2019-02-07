package Controllers.GUIViewControllerFactory.Controllers;

import Controllers.GUIViewControllerFactory.Controller;
import Controllers.GUIViewControllerFactory.ControllerCreators.MenuControllerCreator;
import Controllers.GUIViewControllerFactory.ControllerFactory;

public class MenuController implements Controller {
    static {
        ControllerFactory.getInstance().registerController("Menu", new MenuControllerCreator());
    }

    @Override
    public void handleEvent() {

    }
}
