package ru.nsu.ccfit.bayramov.commands;

public class LoginCommand extends Command {
    private String userName;

    public LoginCommand(String userName) {
        commandType = "login";

        this.userName = userName;
    }
}
