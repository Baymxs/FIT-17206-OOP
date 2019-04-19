package ru.nsu.ccfit.bayramov.chat_server;

import com.google.gson.Gson;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import com.google.gson.JsonObject;
import org.apache.log4j.Logger;
import ru.nsu.ccfit.bayramov.chat_server.commands.*;

class Server {
    private static final Logger log = Logger.getLogger(Server.class);

    private static final int port = 8081;
    private static final int users = 50;
    private Socket clientSocket;
    private Map<String, PrintWriter> clients;

    Gson jsonSerializer = new Gson();

    void start() throws IOException {
        ExecutorService executorService = Executors.newFixedThreadPool(users);

        clients = new HashMap<>();

        try (ServerSocket serverSocket = new ServerSocket(port)) {
            log.info(serverSocket + " is available now.");

            while (true) {
                clientSocket = serverSocket.accept();

                executorService.submit(new ClientHandler(clientSocket));

                log.info("Got a connection with: " + clientSocket);
            }
        }
    }

    public class ClientHandler implements Runnable {
        Socket socket;
        BufferedReader bufferedReader;

        ClientHandler(Socket socket) throws IOException {
            this.socket = socket;
            bufferedReader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        }

        @Override
        public void run() {
            String json;
            try {
                while ((json = bufferedReader.readLine()) != null) {
                    log.info("Received a json from " + socket.getInetAddress() + ": " + json);

                    JsonObject jsonObject = new Gson().fromJson(json, JsonObject.class);

                    String commandType = jsonObject.get("commandType").getAsString();

                    switch (commandType) {
                        case "loginClientCommand":
                            log.info("User " + jsonObject.get("userName").getAsString() + "(" + socket.getInetAddress() + ")" + " connected to the server.");

                            PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(clientSocket.getOutputStream())), true);
                            clients.put(jsonObject.get("userName").getAsString(), out);

                            tellEveryone(new LoginServerCommand(jsonObject.get("userName").getAsString()));
                            tellEveryone(new ListServerCommand(new ArrayList<>(clients.keySet())));

                            break;
                        case "logoutClientCommand":
                            log.info("User " + jsonObject.get("userName").getAsString() + "(" + socket.getInetAddress() + ")" + " disconnected from the server.");

                            clients.remove(jsonObject.get("userName").getAsString());

                            tellEveryone(new LogoutServerCommand(jsonObject.get("userName").getAsString()));
                            tellEveryone(new ListServerCommand(new ArrayList<>(clients.keySet())));

                            break;
                        case "messageClientCommand":
                            log.info("User " + jsonObject.get("userName").getAsString() + "(" + socket.getInetAddress() + ")" + " told for everyone: " + jsonObject.get("message").getAsString());

                            tellEveryone(new MessageServerCommand(jsonObject.get("userName").getAsString(), jsonObject.get("message").getAsString()));

                            break;
                    }
                }
            } catch (Exception ex) {
                ex.printStackTrace();
            }
        }
    }

    private void tellEveryone(Command command) {
        String json = jsonSerializer.toJson(command);
        for (PrintWriter printWriter : clients.values()) {
            printWriter.println(json);
        }
    }
}
