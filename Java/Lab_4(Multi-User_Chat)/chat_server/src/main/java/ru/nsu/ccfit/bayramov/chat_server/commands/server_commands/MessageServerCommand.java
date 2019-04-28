package ru.nsu.ccfit.bayramov.chat_server.commands.server_commands;

import ru.nsu.ccfit.bayramov.chat_server.commands.Command;

public class MessageServerCommand extends Command {
    String userName;
    String message;

    public MessageServerCommand(String userName, String message) {
        commandType = "messageServerCommand";

        this.userName = userName;
        this.message = message;
    }
}
