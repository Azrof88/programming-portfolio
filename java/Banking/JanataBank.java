package Banking;

public class JanataBank implements Bank {
    public double getInterestRate(String accountType) {
        return accountType.equals("Savings") ? 0.01 : 0.025;
    }

}
