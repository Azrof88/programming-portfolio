package stagenography;

public class Main {
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
