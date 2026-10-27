// keytool -genseckey -alias blowfishkey -keyalg Blowfish -keysize 128 -keystore blowfish.jceks -storetype JCEKS
// put some password 123456

//code:
import javax.crypto.*;
import java.security.*;
import java.io.*;
import java.util.*;

public class Blowfishdemo {
    public static void main(String[] args) throws Exception {

        KeyStore ks = KeyStore.getInstance("JCEKS");

        FileInputStream fis =
            new FileInputStream("blowfish.jceks");

        ks.load(fis, "123456".toCharArray());
        fis.close();

        Key key = ks.getKey(
            "blowfishkey", "123456".toCharArray());

        Cipher cipher = Cipher.getInstance("Blowfish");

        cipher.init(Cipher.ENCRYPT_MODE, key);

        byte[] encrypted =
            cipher.doFinal("Hello world".getBytes("UTF-8"));

        String ciphertext =
            Base64.getEncoder().encodeToString(encrypted);

        System.out.println("Encrypted: " + ciphertext);

        cipher.init(Cipher.DECRYPT_MODE, key);

        byte[] decrypted = cipher.doFinal(
            Base64.getDecoder().decode(ciphertext));

        System.out.println(
            "Decrypted: " + new String(decrypted, "UTF-8"));
    }
}

//then do: javac Blowfishdemo.java ; java Blowfishdemo

//output:
Encrypted: TCTmkNepf+A0w7vA6ph9/g==
Decrypted: Hello world
