nano Blowfish.java
code:

import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;
import java.util.Scanner;

public class Blowfish {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Plain Text: ");
        String plainText = sc.nextLine();

        System.out.print("Enter Key: ");
        String keyText = sc.nextLine();

        SecretKey key = new SecretKeySpec(keyText.getBytes(), "Blowfish");

        Cipher cipher = Cipher.getInstance("Blowfish");

        cipher.init(Cipher.ENCRYPT_MODE, key);
        byte[] encrypted = cipher.doFinal(plainText.getBytes());

        System.out.print("Encrypted Text (Hex): ");
        for (byte b : encrypted) {
            System.out.printf("%02X", b);
        }
        System.out.println();

        cipher.init(Cipher.DECRYPT_MODE, key);
        byte[] decrypted = cipher.doFinal(encrypted);

        System.out.println("Decrypted Text: " + new String(decrypted));

        sc.close();
    }
}

// Output:
// Enter Plain Text: hello world
// Enter Key: mysecretkey
// Encrypted Text (Hex): C79562A5E70CB3610F7FA9342A377B4E
// Decrypted Text: hello world
