// nano rsademo.java

  GNU nano 8.7.1                   rsademo.java
import java.security.*;
import javax.crypto.Cipher;
import java.util.Base64;

public class rsademo {
    public static void main(String[] args) throws Exception {

        // Generate RSA keys
        KeyPairGenerator kpg =
            KeyPairGenerator.getInstance("RSA");

        kpg.initialize(2048);
        KeyPair kp = kpg.generateKeyPair();

        PublicKey publicKey = kp.getPublic();
        PrivateKey privateKey = kp.getPrivate();

        String message = "Hello world";

        // Encryption
        Cipher cipher = Cipher.getInstance("RSA");
        cipher.init(Cipher.ENCRYPT_MODE, publicKey);

        byte[] encrypted =
            cipher.doFinal(message.getBytes("UTF-8"));

        System.out.println("Encrypted: " +
            Base64.getEncoder().encodeToString(encrypted));

        // Decryption
        cipher.init(Cipher.DECRYPT_MODE, privateKey);

        byte[] decrypted = cipher.doFinal(encrypted);

        System.out.println("Decrypted: " +
            new String(decrypted, "UTF-8"));
    }
}

javac rsademo.java
java rsademo

//output:
Encrypted: ZdBPDegqRdz/HsiRNtAt4gGTbbIGT2swOgwYuex7XLaCBu2e2CY4yR/GjmfpmrCZ+N60rxlxSpXg4XM3K5DL5F1toRcLvPsz+eSo00JaLaEs0nSyjllG0TGOmW3wYGthXlwnv/pn4sOSsHpU1kkuzoXZ3oPzwtHZdEJ22S+w7O+EKj228zfdKq/xyVCfIRMzYpsDpnxCTnG8u1YopZ/DyEm/YD1VNrrI6jjMl4iV/AzZjPQxs+/XxI/bVi6jWxDM/udVtfLbpaXIprm4OxLZBmiyOIIgClmz6ndvc93uilAd2bRqYeC1ByzylsIO0a2h2UE/X+TRNbG1sa+wCFS30w==
Decrypted: Hello world








