package ru.nsu.ccfit.bayramov.chat_server;

import com.google.gson.Gson;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class Server {
    private static final int port = 8081;
    private static final int users = 50;
    private ArrayList<PrintWriter> clientOutputStreams;

    void start() throws IOException {
        ExecutorService executorService = Executors.newFixedThreadPool(users);

        clientOutputStreams = new ArrayList<>();

        try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("Server " + serverSocket + " is available now.");

            while (true) {
                Socket clientSocket = serverSocket.accept();

                PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(clientSocket.getOutputStream())), true);
                clientOutputStreams.add(out);

                executorService.submit(new ClientHandler(clientSocket));

                System.out.println("Got a connection with: " + clientSocket);
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
            Gson gsonDeserializer = new Gson();
            try {
                while ((json = bufferedReader.readLine()) != null) {
                    System.out.println("Received a json message: " + json);
                }
            } catch (Exception ex) {
                ex.printStackTrace();
            }
        }
    }

    private void tellEveryone(String message) {
        for (PrintWriter printWriter : clientOutputStreams) {
            printWriter.println(message);
        }
    }
}
