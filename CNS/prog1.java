nano StringOperations.java

public class StringOperations {
    public static void main(String[] args) {
        String str = "Hello world";

        System.out.println("Original String: " + str);
        System.out.println();

        System.out.println("Character\tXOR 0\tXOR 127\tAND 0\tAND 127");

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);

            int xor0 = ch ^ 0;
            int xor127 = ch ^ 127;
            int and0 = ch & 0;
            int and127 = ch & 127;

            System.out.println(ch + "\t\t" + xor0 + "\t" +
                xor127 + "\t" + and0 + "\t" + and127);
        }
    }
}

// output:
// Original String: Hello world

// Character       XOR 0   XOR 127 AND 0   AND 127
// H               72      55      0       72
// e               101     26      0       101
// l               108     19      0       108
// l               108     19      0       108
// o               111     16      0       111
//                 32      95      0       32
// w               119     8       0       119
// o               111     16      0       111
// r               114     13      0       114
// l               108     19      0       108
// d               100     27      0       100
