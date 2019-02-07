package ViewFactory.Views;

import ViewFactory.ViewCreators.GUIViewCreator;
import ViewFactory.ViewFactory;
import ViewFactory.View;

public class GUIView implements View {
    static {
        ViewFactory.getInstance().registerView("GUI", new GUIViewCreator());
    }

    @Override
    public void render() {

    }
}
