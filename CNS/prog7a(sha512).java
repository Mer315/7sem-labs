nano sha512.java

//code:
import java.security.*;
import java.util.*;

public class sha512 {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter text: ");
        String text = sc.nextLine();

        MessageDigest md = MessageDigest.getInstance("SHA-512");

        byte[] hash = md.digest(text.getBytes("UTF-8"));

        StringBuilder hex = new StringBuilder();

        for (byte b : hash) {
            hex.append(String.format("%02x", b & 0xff));
        }

        System.out.println("SHA-512 Digest: " + hex);

        sc.close();
    }
}

// javac sha512.java
// java sha512

//output:
Enter text: Hello world
SHA-512 Digest: b7f783baed8297f0db917462184ff4f08e69c2d5e5f79a942600f9725f58ce1f29c18139bf80b06c0fff2bdd34738452ecf40c488c22a7e3d80cdf6f9c1c0d47
