public class Azrof {
    // Method to encode the binary message
    public String encodeMessage(String binaryMessage) {
        StringBuilder encodedMessage = new StringBuilder();
        for (char bit : binaryMessage.toCharArray()) {
            if (bit == '1') {
                encodedMessage.append("\\");
            } else if (bit == '0') {
                encodedMessage.append(" ");
            }
        }
        return encodedMessage.toString();
    }
}

public class Shuchi {
    // Method to decode the encoded message
    public String decodeMessage(String encodedMessage) {
        StringBuilder binaryMessage = new StringBuilder();
        for (char ch : encodedMessage.toCharArray()) {
            if (ch == '\\') {
                binaryMessage.append('1');
            } else if (ch == ' ') {
                binaryMessage.append('0');
            }
        }
        return binaryMessage.toString();
    }
}

public class stagenography {
    public static void main(String[] args) {
        // Create instances of Azrof and Shuchi
        Azrof azrof = new Azrof();
        Shuchi shuchi = new Shuchi();

        // Original binary message
        String binaryMessage = "1011001"; // Example binary message
        System.out.println("Original Binary Message: " + binaryMessage);

        // Azrof encodes the message
        String encodedMessage = azrof.encodeMessage(binaryMessage);
        System.out.println("Encoded Message: " + encodedMessage); // Output will be "\ \ "

        // Shuchi decodes the message
        String decodedMessage = shuchi.decodeMessage(encodedMessage);
        System.out.println("Decoded Binary Message: " + decodedMessage); // Should match the original message
    }
}
