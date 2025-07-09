package UDP;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) throws SocketException {
        Scanner sc = new Scanner(System.in);
        try {
            DatagramSocket ds = new DatagramSocket();

            InetAddress ip = InetAddress.getLocalHost();
            byte buf[] = null;

            while (true) {
                String inp = sc.nextLine();

                buf = inp.getBytes();
                DatagramPacket Dpsend = new DatagramPacket(buf, buf.length, ip, 3010);
                ds.send(Dpsend);

                if (inp.equals("bye")) {
                    break;
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        sc.close();
    }
}
