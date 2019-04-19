package ru.nsu.ccfit.bayramov.chat_client.model.commands;

public class MessageClientCommand extends Command {
    String message;
    String userName;

    public MessageClientCommand(String userName, String message) {
        commandType = "messageClientCommand";

        this.userName = userName;
        this.message = message;
    }
}
