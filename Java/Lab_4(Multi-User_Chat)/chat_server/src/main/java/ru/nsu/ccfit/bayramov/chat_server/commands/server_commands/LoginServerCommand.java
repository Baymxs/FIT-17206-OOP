package ru.nsu.ccfit.bayramov.chat_server.commands.server_commands;

import ru.nsu.ccfit.bayramov.chat_server.commands.Command;

public class LoginServerCommand extends Command {
    String userName;

    public LoginServerCommand(String userName) {
        commandType = "loginServerCommand";

        this.userName = userName;
    }
}
