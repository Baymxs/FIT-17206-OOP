package ViewFactory.ViewCreators;

import ViewFactory.View;
import ViewFactory.ViewCreator;
import ViewFactory.Views.GUIView;

public class GUIViewCreator implements ViewCreator{
    @Override
    public View create() {
        return new GUIView();
    }
}
