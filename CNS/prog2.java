nano CaesarCipher.java

code:
import java.util.Scanner;

public class Prog2a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the message: ");
        String text = sc.nextLine();

        System.out.print("Enter the key (shift value): ");
        int key = sc.nextInt();

        String encrypted = "";
        String decrypted = "";

        for (int i = 0; i < text.length(); i++) {
            char ch = text.charAt(i);

            if (Character.isUpperCase(ch))
                encrypted += (char)((ch - 'A' + key) % 26 + 'A');
            else if (Character.isLowerCase(ch))
                encrypted += (char)((ch - 'a' + key) % 26 + 'a');
            else
                encrypted += ch;
        }

        for (int i = 0; i < encrypted.length(); i++) {
            char ch = encrypted.charAt(i);

            if (Character.isUpperCase(ch))
                decrypted += (char)((ch - 'A' - key + 26) % 26 + 'A');
            else if (Character.isLowerCase(ch))
                decrypted += (char)((ch - 'a' - key + 26) % 26 + 'a');
            else
                decrypted += ch;
        }

        System.out.println("\nEncrypted Text: " + encrypted);
        System.out.println("Decrypted Text: " + decrypted);

        sc.close();
    }
}

// output:
// Enter plaintext: HELLO WORLD
// Enter key: 3

// Encrypted Text: KHOOR ZRUOG
// Decrypted Text: HELLO WORLD
