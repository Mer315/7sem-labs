nano RC4.java
code:

import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import java.util.Scanner;

public class RC4 {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Plain Text: ");
        String plainText = sc.nextLine();

        System.out.print("Enter Key: ");
        String keyText = sc.nextLine();

        SecretKeySpec key = new SecretKeySpec(keyText.getBytes(), "RC4");

        Cipher cipher = Cipher.getInstance("RC4");

        // Encryption
        cipher.init(Cipher.ENCRYPT_MODE, key);
        byte[] encrypted = cipher.doFinal(plainText.getBytes());

        System.out.print("Encrypted Text (Hex): ");
        for (byte b : encrypted) {
            System.out.printf("%02X", b);
        }
        System.out.println();

        // Decryption
        cipher.init(Cipher.DECRYPT_MODE, key);
        byte[] decrypted = cipher.doFinal(encrypted);

        System.out.println("Decrypted Text: " + new String(decrypted));

        sc.close();
    }
}

// output:
// Enter Plain Text: hello world
// Enter Key: secretkey
// Encrypted Text (Hex): CDCDB0702391E2275AC02F
// Decrypted Text: hello world
