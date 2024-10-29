package Banking;

public class SonaliBank implements Bank {
    public double getInterestRate(String accountType) {
        return accountType.equals("Savings") ? 0.01 : 0.02;
    }

}
