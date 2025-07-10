package UDP;
import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class Server {
    public static void main(String[] args) {
        try {
            DatagramSocket ds = new DatagramSocket(3010);
            byte receive[] = new byte[65535];

            DatagramPacket Dpreceive = null;

            while (true) {
                Dpreceive = new DatagramPacket(receive, receive.length);

                ds.receive(Dpreceive);
                System.out.println("Client: " + data(receive));

                if (data(receive).toString().equals("bye")) {
                    System.out.println("Client Exited");
                    break;
                }
                receive = new byte[65535];
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static StringBuilder data(byte a[]) {
        if (a == null)
            return null;
        StringBuilder res = new StringBuilder();
        int i = 0;
        while (a[i] != 0) {
            res.append((char) a[i]);
            i++;
        }
        return res;
    }
}
