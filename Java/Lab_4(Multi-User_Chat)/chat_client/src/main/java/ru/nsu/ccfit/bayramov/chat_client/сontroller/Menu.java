package ru.nsu.ccfit.bayramov.chat_client.сontroller;

import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;
import ru.nsu.ccfit.bayramov.chat_client.model.EventListener;
import ru.nsu.ccfit.bayramov.chat_client.model.Model;

import java.net.URL;
import java.util.ResourceBundle;


public class Menu implements Initializable, EventListener {

    @FXML
    private TextField userNameField;

    @FXML
    private TextField IPAddressField;

    @FXML
    private TextField portField;

    @FXML
    private Label errorLabel;

    private Model model = Model.getInstance();

    private MouseEvent event;


    @Override
    public void initialize(URL location, ResourceBundle resources) {
        model.getEventManager().subscribe( this, "loginResponse");
    }

    @Override
    public void update(String eventType, String message) {
        Platform.runLater(() -> {
            if (eventType.equals("loginResponse")) {
                if (!message.equals("success")) {
                    errorLabel.setText(message);
                    errorLabel.setVisible(true);
                } else {
                    errorLabel.setVisible(false);

                    try {
                        Parent chatViewParent = FXMLLoader.load(getClass().getResource("../view/chat.fxml"));

                        Scene chatViewScene = new Scene(chatViewParent);

                        Stage window = (Stage) ((Node) event.getSource()).getScene().getWindow();
                        window.setOnCloseRequest(we -> Model.getInstance().finishSession());

                        window.setScene(chatViewScene);
                        window.show();

                    } catch (Exception ignored) {
                    }
                }
            }
        });
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public void joinButtonClicked(MouseEvent event) {
        this.event = event;
        try {
            model.startUp(userNameField.getText(), IPAddressField.getText(), portField.getText());
         } catch (Exception e) {
            e.printStackTrace();
            errorLabel.setText("Incorrect server address");
            errorLabel.setVisible(true);
        }
    }

}
