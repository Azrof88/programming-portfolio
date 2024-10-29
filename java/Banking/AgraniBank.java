package Banking;

public class AgraniBank implements Bank {
    public double getInterestRate(String accountType) {
        return accountType.equals("Savings") ? 0.01 : 0.03;
    }

}
