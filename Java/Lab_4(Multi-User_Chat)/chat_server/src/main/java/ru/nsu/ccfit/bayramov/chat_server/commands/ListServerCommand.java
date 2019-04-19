package ru.nsu.ccfit.bayramov.chat_server.commands;

import java.util.List;

public class ListServerCommand extends Command {
    public List<String> userNames;

    public ListServerCommand(List<String> userNames) {
        commandType = "listServerCommand";

        this.userNames = userNames;
    }
}
