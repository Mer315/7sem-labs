//uppercase convert version

nano UpperServer.java
code:

import java.net.*;
import java.io.*;

public class UpperServer {
    public static void main(String[] args) throws Exception {
        ServerSocket server = new ServerSocket(5000);
        System.out.println("Server waiting...");

        Socket socket = server.accept();
        System.out.println("Client connected!");

        BufferedReader in = new BufferedReader(
            new InputStreamReader(socket.getInputStream()));

        PrintWriter out = new PrintWriter(
            socket.getOutputStream(), true);

        String msg;

        while ((msg = in.readLine()) != null) {
            System.out.println("Client: " + msg);

            if (msg.equalsIgnoreCase("bye")) {
                out.println("bye");
                break;
            }

            out.println(msg.toUpperCase());
        }

        socket.close();
        server.close();
    }
}

nano UpperClient.java
code:

import java.net.*;
import java.io.*;
import java.util.Scanner;

public class UpperClient {
    public static void main(String[] args) throws Exception {
        Socket socket = new Socket("localhost", 5000);

        BufferedReader in = new BufferedReader(
            new InputStreamReader(socket.getInputStream()));

        PrintWriter out = new PrintWriter(
            socket.getOutputStream(), true);

        Scanner sc = new Scanner(System.in);

        String msg, reply;

        while (true) {
            System.out.print("Enter message: ");
            msg = sc.nextLine();

            out.println(msg);

            reply = in.readLine();
            System.out.println("Server: " + reply);

            if (msg.equalsIgnoreCase("bye"))
                break;
        }

        socket.close();
        sc.close();
    }
}


// output:
// client
// Enter message: hello
// Server: HELLO

// Enter message: good morning
// Server: GOOD MORNING

// Enter message: bye
// Server: bye

// server
// Server waiting...
// Client connected!
// Client: hello
// Client: good morning
// Client: bye
