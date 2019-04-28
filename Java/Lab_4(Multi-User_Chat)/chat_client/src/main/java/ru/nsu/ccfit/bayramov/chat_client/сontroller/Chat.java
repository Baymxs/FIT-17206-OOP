package ru.nsu.ccfit.bayramov.chat_client.сontroller;

import javafx.application.Platform;
import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.Event;
import javafx.fxml.FXML;
import javafx.scene.paint.Color;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.scene.text.*;
import javafx.stage.Stage;
import ru.nsu.ccfit.bayramov.chat_client.model.EventListener;
import ru.nsu.ccfit.bayramov.chat_client.model.Model;

import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.ResourceBundle;

public class Chat implements Initializable, EventListener {
    @FXML
    public ListView<TextFlow> messagesListView;

    @FXML
    public ListView<Text> usersListView;

    @FXML
    public TextField messageField;

    @FXML
    public Button messageSendButton;

    @FXML
    public Button quitButton;

    private static  Model model = Model.getInstance();

    private ListProperty<TextFlow> messagesListProperty = new SimpleListProperty<>();
    private ObservableList<TextFlow> messagesObservableList = FXCollections.observableArrayList();

    private ListProperty<Text> usersListProperty = new SimpleListProperty<>();

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        model.getEventManager().subscribe( this, "login", "logout", "message", "list");

        messagesListView.itemsProperty().bind(messagesListProperty);
        messagesListView.setMouseTransparent(true);
        messagesListView.setFocusTraversable(false);

        usersListView.itemsProperty().bind(usersListProperty);
    }

    @Override
    public void update(String eventType, List<String> userNames) {
        Platform.runLater(() -> {
            if (eventType.equals("list")) {
                refreshUsersListView(userNames);
            }
        });
    }

    @Override
    public void update(String eventType, String userName, String message) {
        Platform.runLater(() -> {
            if (eventType.equals("message")) {
                refreshMessagesListView(userName, message);
            }
        });
    }

    @Override
    public void update(String eventType, String message) {
        Platform.runLater(() -> {
            if (eventType.equals("login") || eventType.equals("logout")) {
                refreshMessagesListView("", message);
            }
        });
    }

    private void refreshMessagesListView(String userName, String message) {
        TextFlow textFlow = new TextFlow();

        if (userName.equals("")) {
            Text messageText = new Text(message);
            messageText.setFill(Color.rgb(66, 100, 139));

            textFlow.getChildren().addAll(messageText);
        } else {
            Text userNameText = new Text(userName + ": ");
            userNameText.setFill(Color.rgb(66, 100, 139));

            textFlow.getChildren().addAll(userNameText, new Text(message));
        }

        messagesObservableList.add(textFlow);
        messagesListProperty.setValue(messagesObservableList);
    }

    private void refreshUsersListView(List<String> userNames) {
        List<Text> usersTextList = new ArrayList<>();

        for (String userName : userNames) {
            Text userNameText = new Text(userName);
            userNameText.setFill(Color.rgb(66, 100, 139));

            usersTextList.add(userNameText);
        }

        usersListProperty.setValue(FXCollections.observableArrayList(usersTextList));
    }

    public void sendButtonClicked() {
        model.sendMessage(messageField.getText());

        messageField.clear();
    }

    public void quitButtonClicked(MouseEvent event) throws IOException {
        model.getEventManager().unsubscribe(this, "login", "logout", "message", "list");
        model.clearUserNames();
        model.finishSession();

        messagesObservableList.clear();
        messagesListProperty.setValue(messagesObservableList);

        usersListProperty.setValue(FXCollections.observableArrayList());

        Parent chatViewParent = FXMLLoader.load(getClass().getResource("../view/menu.fxml"));

        Scene chatViewScene = new Scene(chatViewParent);

        Stage window = (Stage)((Node)event.getSource()).getScene().getWindow();

        window.setScene(chatViewScene);
        window.show();
    }
}
