nano des.java

code:
import java.util.Base64;
import java.util.Scanner;
import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;

public class des {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Plain Text: ");
        String plainText = sc.nextLine();

        System.out.print("Enter 8-character Key: ");
        String key = sc.nextLine();

        while (key.length() != 8) {
            System.out.print("Key must be exactly 8 characters: ");
            key = sc.nextLine();
        }

        SecretKey secretKey = new SecretKeySpec(key.getBytes(), "DES");

        Cipher cipher = Cipher.getInstance("DES");

        cipher.init(Cipher.ENCRYPT_MODE, secretKey);
        byte[] encrypted = cipher.doFinal(plainText.getBytes());

        String encryptedText = Base64.getEncoder().encodeToString(encrypted);
        System.out.println("\nEncrypted Text: " + encryptedText);

        cipher.init(Cipher.DECRYPT_MODE, secretKey);
        byte[] decrypted = cipher.doFinal(encrypted);

        System.out.println("Decrypted Text: " + new String(decrypted));

        sc.close();
    }
}

// output:
// Enter Plain Text: Hello World
// Enter 8-character Key: 12345678

// Encrypted Text: 01Jk6AecyqldguNoHIO7dw==
// Decrypted Text: Hello World
