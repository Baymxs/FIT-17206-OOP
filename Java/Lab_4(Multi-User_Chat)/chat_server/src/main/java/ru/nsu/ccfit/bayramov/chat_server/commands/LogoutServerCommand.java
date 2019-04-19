package ru.nsu.ccfit.bayramov.chat_server.commands;

public class LogoutServerCommand extends Command {
    String userName;

    public LogoutServerCommand(String userName) {
        commandType = "logoutServerCommand";

        this.userName = userName;
    }
}
