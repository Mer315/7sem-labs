//client and server reflection. client type bye, communication over

nano EchoServer.java
code:
import java.net.*;
import java.io.*;

public class EchoServer {
    public static void main(String[] args) throws Exception {
        ServerSocket server = new ServerSocket(5000);
        System.out.println("Server waiting for client...");

        Socket socket = server.accept();
        System.out.println("Client connected!");

        BufferedReader in = new BufferedReader(
            new InputStreamReader(socket.getInputStream()));

        PrintWriter out = new PrintWriter(
            socket.getOutputStream(), true);

        String msg;

        while ((msg = in.readLine()) != null) {
            System.out.println("Client: " + msg);
            out.println(msg);

            if (msg.equalsIgnoreCase("bye"))
                break;
        }

        socket.close();
        server.close();
    }
}

nano EchoClient.java
code:
import java.net.*;
import java.io.*;
import java.util.Scanner;

public class EchoClient {
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



// Client
//   Enter message: Hello
// Server: Hello
// Enter message: How are you?
// Server: How are you?
// Enter message: bye
// Server: bye

// Server
//   Server waiting for client...
// Client connected!
// Client: Hello
// Client: How are you?
// Client: bye
