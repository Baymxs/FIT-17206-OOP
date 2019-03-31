package ru.nsu.ccfit.bayramov.Minesweeper.Controller;

import javafx.collections.ObservableList;
import javafx.event.Event;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.geometry.Pos;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.stage.Stage;

import java.io.*;
import java.net.URL;
import java.util.Properties;
import java.util.ResourceBundle;

public class ScoresController implements Initializable {
    private final static Image simpleBackButton = new Image("ru/nsu/ccfit/bayramov/Minesweeper/Buttons/BackButton/back_button.png");
    private final static Image movedBackButton = new Image("ru/nsu/ccfit/bayramov/Minesweeper/Buttons/BackButton/moved_back_button.png");

    private Properties scoresProperties = new Properties();

    @FXML
    private ImageView backButton;

    @FXML
    private GridPane scorePanel;

    @FXML
    private GridPane rankPanel;

    @Override
    public void initialize(URL location, ResourceBundle resources) {

        File initialFile = new File("src/main/resources/ru/nsu/ccfit/bayramov/Minesweeper/scores.properties");
        try {
            InputStream targetStream = new FileInputStream(initialFile);
            scoresProperties.load(targetStream);
        } catch (IOException e) {
            e.printStackTrace();
        }

        for (int i = 0; i < 5; i++) {
            Label label1 = new Label();
            label1.setText(Integer.toString(i + 1));
            label1.setAlignment(Pos.CENTER);
            label1.setFont(new Font("System", 65));
            label1.setTextFill(Color.web("#ffffff"));

            Label label2 = new Label();
            label2.setText(scoresProperties.getProperty(Integer.toString(i)));
            label2.setAlignment(Pos.CENTER);
            label2.setFont(new Font("System", 65));
            label2.setTextFill(Color.web("#00e0ff"));

            scorePanel.add(label1, 0, i);
            scorePanel.add(label2, 1, i);
        }
    }

    public void backButtonClicked(Event event) throws IOException {
        Parent menuViewParent = FXMLLoader.load(getClass().getResource("../View/Menu.fxml"));

        Scene menuViewScene = new Scene(menuViewParent);

        Stage window = (Stage)((Node)event.getSource()).getScene().getWindow();

        window.setScene(menuViewScene);
        window.show();
    }

    public void backButtonMoved() {
        backButton.setImage(movedBackButton);
    }

    public void backButtonExited() {
        backButton.setImage(simpleBackButton);
    }
}
