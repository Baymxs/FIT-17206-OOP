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
import ru.nsu.ccfit.bayramov.chat_server.commands.response_commands.login.LoginErrorResponse;
import ru.nsu.ccfit.bayramov.chat_server.commands.response_commands.login.LoginSuccessResponse;
import ru.nsu.ccfit.bayramov.chat_server.commands.server_commands.ListServerCommand;
import ru.nsu.ccfit.bayramov.chat_server.commands.server_commands.LoginServerCommand;
import ru.nsu.ccfit.bayramov.chat_server.commands.server_commands.LogoutServerCommand;
import ru.nsu.ccfit.bayramov.chat_server.commands.server_commands.MessageServerCommand;

class Server {
    private static final Logger log = Logger.getLogger(Server.class);

    private final int port = 8081;
    private final int users = 20;
    private int currentUsers = 0;
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
            String userName = null;

            try {
                while ((json = bufferedReader.readLine()) != null) {
                    log.info("Received a json from " + socket.getInetAddress() + ": " + json);

                    JsonObject jsonObject = new Gson().fromJson(json, JsonObject.class);

                    String commandType = jsonObject.get("commandType").getAsString();

                    switch (commandType) {
                        case "loginClientCommand":
                            PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(clientSocket.getOutputStream())), true);

                            if (clients.containsKey(jsonObject.get("userName").getAsString())) {
                                log.info(jsonObject.get("userName").getAsString() + " user name has already taken");

                                out.println(jsonSerializer.toJson(new LoginErrorResponse("This user name has already taken")));
                            } else if (currentUsers == users) {
                                log.info("Maximum number of users exceeded");

                                out.println(jsonSerializer.toJson(new LoginErrorResponse("Maximum number of users exceeded")));
                            } else {
                                log.info("User " + jsonObject.get("userName").getAsString() + "(" + socket.getInetAddress() + ")" + " connected to the server.");

                                userName = jsonObject.get("userName").getAsString();

                                clients.put(jsonObject.get("userName").getAsString(), out);
                                currentUsers++;

                                out.println(jsonSerializer.toJson(new LoginSuccessResponse()));

                                tellEveryone(new LoginServerCommand(jsonObject.get("userName").getAsString()));
                                tellEveryone(new ListServerCommand(new ArrayList<>(clients.keySet())));
                            }

                            break;
                        case "logoutClientCommand":
                            log.info("User " + jsonObject.get("userName").getAsString() + "(" + socket.getInetAddress() + ")" + " disconnected from the server.");

                            clients.get(userName).println(jsonSerializer.toJson(new LogoutServerCommand(jsonObject.get("userName").getAsString())));

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

            clients.remove(userName);
            currentUsers--;

            tellEveryone(new ListServerCommand(new ArrayList<>(clients.keySet())));
        }
    }

    private void tellEveryone(Command command) {
        String json = jsonSerializer.toJson(command);
        for (PrintWriter printWriter : clients.values()) {
            printWriter.println(json);
        }
    }
}
