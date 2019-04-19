package ru.nsu.ccfit.bayramov.chat_client.model;

import com.google.gson.Gson;
import com.google.gson.JsonObject;
import ru.nsu.ccfit.bayramov.chat_client.model.commands.ServerCommands.ListServerCommand;
import ru.nsu.ccfit.bayramov.chat_client.сontroller.Chat;
import ru.nsu.ccfit.bayramov.chat_client.model.commands.*;


import java.io.*;
import java.net.Socket;

public class Model {
    private static Model instance = new Model();

    private Socket socket;

    private BufferedReader reader;
    private PrintWriter writer;

    private String userName;

    Thread incomingReaderThread;

    Gson jsonSerializer = new Gson();

    private Model() {}

    public static Model getInstance() {
        return instance;
    }

    public void startUp(String userName, String IPAddress, String port) throws IOException {
        socket = new Socket(IPAddress, Integer.parseInt(port));

        reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);

        this.userName = userName;

        incomingReaderThread = new Thread(new IncomingReader());
        incomingReaderThread.start();

        login(userName);

        System.out.println("network established");
    }

    public void finishSession() {
        logout(userName);

        userName = "";
    }

    public class IncomingReader implements Runnable {
        @Override
        public void run() {
            String json;
            try {
                loop:while (((json = reader.readLine()) != null)) {
                    JsonObject jsonObject = new Gson().fromJson(json, JsonObject.class);

                    String commandType = jsonObject.get("commandType").getAsString();
                    System.out.println(json);

                    switch (commandType) {
                        case "loginServerCommand":
                            Chat.refreshMessagesPane(jsonObject.get("userName").getAsString(), " connected to the server! Welcome!");
                            break;
                        case "logoutServerCommand":
                            if (jsonObject.get("userName").getAsString().equals(userName)) {
                                socket.close();
                                break loop;
                            } else {
                                Chat.refreshMessagesPane(jsonObject.get("userName").getAsString(), " disconnected from the server! Goodbye!");
                            }
                            break;
                        case "messageServerCommand":
                            Chat.refreshMessagesPane(jsonObject.get("userName").getAsString() + ": " + jsonObject.get("message").getAsString());
                            break;
                        case "listServerCommand":
                            ListServerCommand listServerCommand = new Gson().fromJson(json, ListServerCommand.class);
                            Chat.refreshUsersPane(listServerCommand.getUserNames());
                    }
                }
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
    }

    public void login(String userName) {
        String json = jsonSerializer.toJson(new LoginClientCommand(userName));
        writer.println(json);
    }

    public void logout(String userName) {
        String json = jsonSerializer.toJson(new LogoutClientCommand(userName));
        writer.println(json);
    }

    public void sendMessage(String message) {
        String json = jsonSerializer.toJson(new MessageClientCommand(userName, message));
        writer.println(json);
    }
}
