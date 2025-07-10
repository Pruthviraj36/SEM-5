package TCP;
import java.net.*;
import java.io.*;

public class Server {
    
    private Socket s = null;
    private ServerSocket ss = null;
    private DataInputStream in = null;

    public Server(int port) {
        try {
            ss = new ServerSocket(port);
            System.out.println("Server Started");
            System.out.println("Waiting for Client");
            s = ss.accept();
            System.out.println("Client Accepted");
            
            in = new DataInputStream(new BufferedInputStream(s.getInputStream()));

            String m = "";

            while (!m.equals("Over")) {
                try {
                    m = in.readUTF();
                    System.out.println(m);
                } catch (Exception e) {
                    System.out.println(e);
                }
            }
            System.out.println("Closing Connection");

            s.close();
            in.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public static void main(String[] args) {
        new Server(3010);
    }
}
