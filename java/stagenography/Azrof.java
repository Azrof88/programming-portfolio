package stagenography;

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
