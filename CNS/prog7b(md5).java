// nano md5.java

//code:
import java.security.*;
import java.util.*;

public class md5 {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter text: ");
        String text = sc.nextLine();

        MessageDigest md = MessageDigest.getInstance("MD5");

        byte[] hash = md.digest(text.getBytes("UTF-8"));

        StringBuilder hex = new StringBuilder();

        for (byte b : hash) {
            hex.append(String.format("%02x", b & 0xff));
        }

        System.out.println("MD5 Digest: " + hex);

        sc.close();
    }
}

// javac md5.java, java md5
//output:

Enter text: Hello world
MD5 Digest: 3e25960a79dbc69b674cd4ec67a72c62
