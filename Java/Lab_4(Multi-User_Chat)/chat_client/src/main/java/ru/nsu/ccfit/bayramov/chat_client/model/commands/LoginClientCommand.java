package ru.nsu.ccfit.bayramov.chat_client.model.commands;

public class LoginClientCommand extends Command {
    private String userName;

    public LoginClientCommand(String userName) {
        commandType = "loginClientCommand";

        this.userName = userName;
    }
}
