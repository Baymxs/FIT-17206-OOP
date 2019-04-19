package ru.nsu.ccfit.bayramov.chat_server.commands;

public class LoginServerCommand extends Command {
    String userName;

    public LoginServerCommand(String userName) {
        commandType = "loginServerCommand";

        this.userName = userName;
    }
}
