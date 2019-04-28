package ru.nsu.ccfit.bayramov.chat_server.commands.response_commands.login;

import ru.nsu.ccfit.bayramov.chat_server.commands.ResponseServerCommand;

public class LoginErrorResponse extends ResponseServerCommand {
    public LoginErrorResponse(String errorMessage) {
        super("loginServerResponse", errorMessage);
    }
}
