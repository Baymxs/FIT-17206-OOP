package ru.nsu.ccfit.bayramov.chat_server.commands;

public abstract class ResponseServerCommand extends Command {
    String response;

    public ResponseServerCommand(String commandType, String response) {
        this.commandType = commandType;
        this.response = response;
    }
}
