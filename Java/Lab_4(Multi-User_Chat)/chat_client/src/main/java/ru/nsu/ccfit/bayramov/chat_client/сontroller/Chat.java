package ru.nsu.ccfit.bayramov.chat_client.сontroller;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.scene.text.Text;
import javafx.scene.text.TextAlignment;
import javafx.stage.Stage;
import ru.nsu.ccfit.bayramov.chat_client.model.Model;

import java.io.IOException;
import java.net.URL;
import java.util.List;
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

    @FXML
    public Button quitButton;

    private static Text messagesText = new Text();

    private static Text usersText = new Text();

    private Model model = Model.getInstance();

    public static void refreshMessagesPane(String userName, String message) {
        Text userNameText = new Text(userName);
        userNameText.setStyle("-fx-font-weight: bold; -fx-background-color: #A5CCFFl;");

        messagesText.setText(messagesText.getText() + message + '\n');
    }

    public static void refreshUsersPane(List<String> users) {
        StringBuilder s = new StringBuilder();

        for (String user : users) {
            s.append(user).append("\n");
        }

        usersText.setText(s.toString());
    }

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        messagesText.wrappingWidthProperty().bind(messagesPane.widthProperty());
        messagesPane.setContent(messagesText);

        usersText.wrappingWidthProperty().bind(usersPane.widthProperty());
        usersText.setTextAlignment(TextAlignment.CENTER);
        usersPane.setContent(usersText);
    }

    public void sendButtonClicked() {
        model.sendMessage(messageField.getText());
        messageField.clear();
    }

    public void quitButtonClicked(MouseEvent event) throws IOException {
        clearMessagesPane();
        clearUsersPane();

        model.finishSession();

        Parent chatViewParent = FXMLLoader.load(getClass().getResource("../view/menu.fxml"));

        Scene chatViewScene = new Scene(chatViewParent);

        Stage window = (Stage)((Node)event.getSource()).getScene().getWindow();

        window.setScene(chatViewScene);
        window.show();
    }

    private void clearMessagesPane() {
        messagesText.setText("");
        messagesPane.setContent(messagesText);
    }

    private void clearUsersPane() {
        usersText.setText("");
        usersPane.setContent(usersText);
    }
}
