nano hillcipher.java

code:
import java.util.Scanner;

public class hillcipher {

    static int[][] key = {{3, 3}, {2, 5}};
    static int[][] inv = {{15, 17}, {20, 9}};

    static String encrypt(String text) {
        text = text.toUpperCase().replaceAll("[^A-Z]", "");

        if (text.length() % 2 != 0)
            text += "X";

        String result = "";

        for (int i = 0; i < text.length(); i += 2) {
            int a = text.charAt(i) - 'A';
            int b = text.charAt(i + 1) - 'A';

            result += (char)((key[0][0]*a + key[0][1]*b) % 26 + 'A');
            result += (char)((key[1][0]*a + key[1][1]*b) % 26 + 'A');
        }

        return result;
    }

    static String decrypt(String text) {
        String result = "";

        for (int i = 0; i < text.length(); i += 2) {
            int a = text.charAt(i) - 'A';
            int b = text.charAt(i + 1) - 'A';

            result += (char)((inv[0][0]*a + inv[0][1]*b) % 26 + 'A');
            result += (char)((inv[1][0]*a + inv[1][1]*b) % 26 + 'A');
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Text: ");
        String text = sc.nextLine();

        String enc = encrypt(text);
        String dec = decrypt(enc);

        System.out.println("Encrypted: " + enc);
        System.out.println("Decrypted: " + dec);

        sc.close();
    }
}

// output:
// Enter Text: HELLO

// Encrypted: HIOZHN
// Decrypted: HELLOX
