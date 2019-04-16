package ru.nsu.ccfit.bayramov.chat_client.model;

import com.google.gson.Gson;
import ru.nsu.ccfit.bayramov.chat_client.сontroller.Chat;
import ru.nsu.ccfit.bayramov.commands.LoginCommand;


import java.io.*;
import java.net.Socket;

public class Model {
    private static Model instance = new Model();

    private BufferedReader reader;
    private PrintWriter writer;

    Gson jsonSerializer = new Gson();

    private Model() {}

    public static Model getInstance() {
        return instance;
    }

    public void startUp(String userName, String IPAddress, String port) throws IOException {
        Socket socket = new Socket(IPAddress, Integer.parseInt(port));

        reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);

        login(userName);

        new Thread(new IncomingReader()).start();

        System.out.println("network established");
    }

    public class IncomingReader implements Runnable {
        @Override
        public void run() {
            String message;
            try {
                while ((message = reader.readLine()) != null) {
                    Chat.refreshMessages(message);
                    System.out.println("New message is: " + message);
                }
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
    }

    public void login(String userName) {
        String json = jsonSerializer.toJson(new LoginCommand(userName));
        writer.println(json);
    }

    public void sendMessageTTServer(String message) {
        writer.println(message);
    }
}
