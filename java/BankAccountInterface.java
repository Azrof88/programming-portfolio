import com.example.mybank.BankAccountInterface;


public interface BankAccountInterface {
    void depositAmount(double amount);

    void withdrawAmount(double amount);

    String displayName();

    double displayBalance();

    String getAccountDetails();

    double getInterestRate();
}
