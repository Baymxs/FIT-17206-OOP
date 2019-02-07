import ViewFactory.View;
import ViewFactory.ViewFactory;
import Controllers.GUIViewControllerFactory.Controller;
import Controllers.GUIViewControllerFactory.ControllerFactory;

public class Minesweeper {
    private MinesweeperModel model;
    private View view;
    private Controller controller;

    Minesweeper(String gameMode) {
        model = new MinesweeperModel(gameMode);
        view = ViewFactory.getInstance().getView(model.getGameMode());
        controller = ControllerFactory.getInstance().getController(model.getGameStage());
    }

    public void start() {

    }
}
