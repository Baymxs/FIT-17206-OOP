package ru.nsu.ccfit.bayramov.chat_client.model.commands.ServerCommands;

import ru.nsu.ccfit.bayramov.chat_client.model.commands.Command;

import java.util.List;

public class ListServerCommand extends Command {
    public List<String> userNames;

    public List<String> getUserNames() {
        return userNames;
    }
}
