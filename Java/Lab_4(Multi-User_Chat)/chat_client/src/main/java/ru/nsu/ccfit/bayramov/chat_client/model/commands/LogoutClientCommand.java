package ru.nsu.ccfit.bayramov.chat_client.model.commands;

public class LogoutClientCommand extends Command {
    private String userName;

    public LogoutClientCommand(String userName) {
        commandType = "logoutClientCommand";

        this.userName = userName;
    }
}
