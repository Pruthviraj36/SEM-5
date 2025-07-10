package TCP;
import java.io.*;
import java.net.*;

public class Client {

    private Socket s = null;
    private DataInputStream in = null;
    private DataOutputStream out = null;

    public Client(String addr, int port){
        try {
            s = new Socket(addr, port);
            System.err.println("Connected");

            in = new DataInputStream(System.in);

            out = new DataOutputStream(s.getOutputStream());
        } catch (Exception e) {
            System.out.println(e);
            return;
        }

        String m = "";

        while (!m.equals("Over")) {
            try {
                m = in.readLine();
                out.writeUTF(m);;
            } catch (Exception e) {
                System.out.println(e);
            }
        }

        try {
            in.close();
            out.close();
            s.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
    public static void main(String[] args) {
        new Client("10.20.42.33", 3010);
    }
}