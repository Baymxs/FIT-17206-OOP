package ru.nsu.ccfit.bayramov.chat_client.model;

import com.google.gson.Gson;
import com.google.gson.JsonObject;
import javafx.application.Platform;
import ru.nsu.ccfit.bayramov.chat_client.model.commands.ServerCommands.ListServerCommand;
import ru.nsu.ccfit.bayramov.chat_client.model.commands.*;
import ru.nsu.ccfit.bayramov.chat_client.сontroller.Chat;


import java.io.*;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;


public class Model {
    private static Model instance = new Model();

    private EventManager events;

    private Gson jsonSerializer;

    private Socket socket;

    private BufferedReader reader;
    private PrintWriter writer;

    private String userName;

    private List<String> userNames;

    private Model() {
        events = new EventManager("login", "loginResponse", "logout", "message", "list", "shutdown");
        jsonSerializer = new Gson();

        userNames = new ArrayList<>();
    }

    public static Model getInstance() {
        return instance;
    }

    public EventManager getEventManager() {
        return events;
    }

    public void startUp(String userName, String IPAddress, String port) throws IOException {
        socket = new Socket(IPAddress, Integer.parseInt(port));

        reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);

        new Thread(new IncomingReader()).start();

        login(userName);

        this.userName = userName;
    }

    public void finishSession() {
        logout(userName);
    }

    public void clearUserNames() {
        userNames.clear();
    }

    public class IncomingReader implements Runnable {
        @Override
        public void run() {
            String json;
            try {
                loop:while (((json = reader.readLine()) != null)) {
                    JsonObject jsonObject = new Gson().fromJson(json, JsonObject.class);

                    String commandType = jsonObject.get("commandType").getAsString();

                    switch (commandType) {
                        case "loginServerResponse":
                            events.notify("loginResponse", jsonObject.get("response").getAsString());
                            if (jsonObject.get("response").getAsString().equals("success")) {
                                events.unsubscribeAll("loginResponse");
                            } else {
                                socket.close();
                                break loop;
                            }
                            break;
                        case "loginServerCommand":
                            events.notify("login", jsonObject.get("userName").getAsString() +" connected to the server.");
                            break;
                        case "logoutServerCommand":
                            if (jsonObject.get("userName").getAsString().equals(userName)) {
                                socket.close();
                                break loop;
                            } else {
                                events.notify("logout", jsonObject.get("userName").getAsString() + " disconnected from the server");
                            }
                            break;
                        case "messageServerCommand":
                            events.notify("message", jsonObject.get("userName").getAsString(), jsonObject.get("message").getAsString());
                            break;
                        case "listServerCommand":
                            userNames.clear();
                            userNames.addAll(new Gson().fromJson(json, ListServerCommand.class).getUserNames());
                            events.notify("list", userNames);
                            break;
                    }
                }
            } catch (IOException ex) {
                ex.printStackTrace();
            }
            events.notify("shutdown", "Server is not available now. Sorry, dude(");
        }
    }

    private void login(String userName) {
        String json = jsonSerializer.toJson(new LoginClientCommand(userName));
        writer.println(json);
    }

    private void logout(String userName) {
        String json = jsonSerializer.toJson(new LogoutClientCommand(userName));
        writer.println(json);
    }

    public void sendMessage(String message) {
        String json = jsonSerializer.toJson(new MessageClientCommand(userName, message));
        writer.println(json);
    }
}
