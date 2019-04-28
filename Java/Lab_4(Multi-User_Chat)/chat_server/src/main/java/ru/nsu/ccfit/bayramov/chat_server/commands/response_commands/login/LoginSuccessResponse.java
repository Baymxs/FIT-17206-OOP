package ru.nsu.ccfit.bayramov.chat_server.commands.response_commands.login;

import ru.nsu.ccfit.bayramov.chat_server.commands.ResponseServerCommand;

public class LoginSuccessResponse extends ResponseServerCommand {
    public LoginSuccessResponse() {
        super("loginServerResponse", "success");
    }
}
