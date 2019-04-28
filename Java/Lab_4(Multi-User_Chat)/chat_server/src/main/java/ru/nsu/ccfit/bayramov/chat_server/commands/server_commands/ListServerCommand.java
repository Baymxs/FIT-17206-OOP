package ru.nsu.ccfit.bayramov.chat_server.commands.server_commands;

import ru.nsu.ccfit.bayramov.chat_server.commands.Command;

import java.util.List;

public class ListServerCommand extends Command {
    public List<String> userNames;

    public ListServerCommand(List<String> userNames) {
        commandType = "listServerCommand";

        this.userNames = userNames;
    }
}
