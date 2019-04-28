package ru.nsu.ccfit.bayramov.chat_server.commands.server_commands;

import ru.nsu.ccfit.bayramov.chat_server.commands.Command;

public class LogoutServerCommand extends Command {
    String userName;

    public LogoutServerCommand(String userName) {
        commandType = "logoutServerCommand";

        this.userName = userName;
    }
}
