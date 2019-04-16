package ru.nsu.ccfit.bayramov.chat_client.сontroller;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.TextField;
import javafx.scene.text.Text;
import ru.nsu.ccfit.bayramov.chat_client.model.Model;

import java.net.URL;
import java.util.ResourceBundle;

public class Chat implements Initializable {
    @FXML
    public ScrollPane messagesPane;

    @FXML
    public ScrollPane usersPane;

    @FXML
    public TextField messageField;

    @FXML
    public Button messageSendButton;

    private static Text messages = new Text();

    private Model model = Model.getInstance();

    public static void refreshMessages(String message) {
        messages.setText(messages.getText() + message + '\n');
    }

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        messages.wrappingWidthProperty().bind(messagesPane.widthProperty());
        messagesPane.setContent(messages);
    }

    public void sendButtonClicked() {
        model.sendMessageTTServer(messageField.getText());
        messageField.clear();
    }
}
