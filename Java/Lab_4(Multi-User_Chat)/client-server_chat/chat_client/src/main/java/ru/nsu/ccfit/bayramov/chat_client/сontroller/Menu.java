package ru.nsu.ccfit.bayramov.chat_client.сontroller;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;
import ru.nsu.ccfit.bayramov.chat_client.model.Model;


public class Menu {

    private Model model = Model.getInstance();

    @FXML
    private TextField userNameField;

    @FXML
    private TextField IPAddressField;

    @FXML
    private TextField portField;

    @FXML
    private Label errorLabel;

    public void joinButtonClicked(MouseEvent event) {
        try {
            model.startUp(userNameField.getText(), IPAddressField.getText(), portField.getText());

            Parent chatViewParent = FXMLLoader.load(getClass().getResource("ru/nsu/ccfit/bayramov/chat_client/view/chat.fxml"));

            Scene chatViewScene = new Scene(chatViewParent);

            Stage window = (Stage)((Node)event.getSource()).getScene().getWindow();

            window.setScene(chatViewScene);
            window.show();
        } catch (Exception e) {
            errorLabel.setVisible(true);
        }
    }
}
