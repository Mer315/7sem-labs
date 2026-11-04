nano AES.java

code:
import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;
import java.util.Scanner;

public class AES {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Plain Text: ");
        String plainText = sc.nextLine();

        System.out.print("Enter 16-character Key: ");
        String keyText = sc.nextLine();

        if (keyText.length() != 16) {
            System.out.println("Key must be exactly 16 characters.");
            return;
        }

        SecretKey key = new SecretKeySpec(keyText.getBytes(), "AES");

        Cipher cipher = Cipher.getInstance("AES");

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

// output:
// Enter Plain Text: Hello World
// Enter 16-character Key: 1234567890123456

// Encrypted Text (Hex): [Ciphertext]
// Decrypted Text: Hello World
