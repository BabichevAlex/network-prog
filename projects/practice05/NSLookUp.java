package practice05;

import java.net.*;
import java.util.Scanner;

public class NSLookUp {
    public static void main(String[] args) {
        String hostName = null;
        if (args.length>1)
            hostName = args[1];
        else{
            System.out.println("Уведіть ім’я хосту");
            Scanner scanner = new Scanner(System.in);
            //hostName = JOptionPane.showInputDialog(cap, "localhost");
            hostName = scanner.nextLine();
            if (hostName==null)
                hostName = "localhost";
        }
        try {
            InetAddress[] ips = InetAddress.getAllByName(hostName);
            for (InetAddress IP:ips){
                System.out.println(IP.getHostAddress());
            }
        } catch (UnknownHostException e) {
            System.out.println(e.getMessage());
        }
    }
}