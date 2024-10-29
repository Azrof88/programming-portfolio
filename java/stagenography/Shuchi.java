package stagenography;

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
