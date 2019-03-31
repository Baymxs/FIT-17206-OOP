package ru.nsu.ccfit.bayramov.Minesweeper.Controller;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;
import ru.nsu.ccfit.bayramov.Minesweeper.Model.GameModel;


import java.io.IOException;

public class MenuController {

    @FXML
    private ImageView startButton;
    private Image movedStartButton = new Image("ru/nsu/ccfit/bayramov/Minesweeper/Buttons/StartButton/MovedStartButton.png");
    private Image exitedStartButton = new Image("ru/nsu/ccfit/bayramov/Minesweeper/Buttons/StartButton/StartButton.png");

    @FXML
    private ImageView optionsButton;
    private Image movedOptionsButton = new Image("ru/nsu/ccfit/bayramov/Minesweeper/Buttons/OptionsButton/MovedOptionsButton.png");
    private Image exitedOptionsButton = new Image("ru/nsu/ccfit/bayramov/Minesweeper/Buttons/OptionsButton/OptionsButton.png");

    @FXML
    private ImageView scoresButton;
    private Image movedScoresButton = new Image("ru/nsu/ccfit/bayramov/Minesweeper/Buttons/ScoresButton/MovedScoresButton.png");
    private Image exitedScoresButton = new Image("ru/nsu/ccfit/bayramov/Minesweeper/Buttons/ScoresButton/ScoresButton.png");

    @FXML
    private ImageView exitButton;
    private Image movedExitButton = new Image("ru/nsu/ccfit/bayramov/Minesweeper/Buttons/ExitButton/MovedExitButton.png");
    private Image exitedExitButton = new Image("ru/nsu/ccfit/bayramov/Minesweeper/Buttons/ExitButton/ExitButton.png");


    public void startButtonPressed(MouseEvent event) throws IOException {
        GameModel.getInstance().setFromMenuWindow(true);

        Parent gameViewParent = FXMLLoader.load(getClass().getResource("../View/Game.fxml"));

        Scene gameViewScene = new Scene(gameViewParent);

        Stage window = (Stage)((Node)event.getSource()).getScene().getWindow();

        window.setScene(gameViewScene);
        window.show();
    }

    public void startButtonMoved() {
        startButton.setImage(movedStartButton);
    }

    public void startButtonExited() {
        startButton.setImage(exitedStartButton);
    }

    public void optionsButtonMoved() {
        optionsButton.setImage(movedOptionsButton);
    }

    public void optionsButtonExited() {
        optionsButton.setImage(exitedOptionsButton);
    }

    public void scoresButtonPressed(MouseEvent event) throws IOException {
        Parent gameViewParent = FXMLLoader.load(getClass().getResource("../View/Scores.fxml"));

        Scene gameViewScene = new Scene(gameViewParent);

        Stage window = (Stage)((Node)event.getSource()).getScene().getWindow();

        window.setScene(gameViewScene);
        window.show();
    }

    public void scoresButtonMoved() {
        scoresButton.setImage(movedScoresButton);
    }

    public void scoresButtonExited() {
        scoresButton.setImage(exitedScoresButton);
    }

    public void exitButtonPressed(MouseEvent event) {
        GameModel.getInstance().setFromMenuWindow(true);

        Stage window = (Stage)((Node)event.getSource()).getScene().getWindow();

        window.close();
    }
    public void exitButtonMoved() {
        exitButton.setImage(movedExitButton);
    }

    public void exitButtonExited() {
        exitButton.setImage(exitedExitButton);
    }
}
