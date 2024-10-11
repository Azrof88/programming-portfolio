package mybank;

public class BankAccount implements BankAccountInterface {
    // Private attributes
    private String depositorName;
    private String typeOfAccount; // "Savings" or "FixedDeposit"
    private String accountNumber;
    private double balance;

    // Constructor
    public BankAccount(String depositorName, String typeOfAccount, String accountNumber, double initialBalance) {
        this.depositorName = depositorName;
        this.typeOfAccount = typeOfAccount;
        this.accountNumber = accountNumber;
        this.balance = initialBalance >= 0 ? initialBalance : 0; // Ensure balance is not negative
    }

    // Method to deposit amount
    @Override
    public void depositAmount(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposited: " + amount);
        } else {
            System.out.println("Deposit amount must be positive.");
        }
    }

    // Method to withdraw amount
    @Override
    public void withdrawAmount(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("Withdrawn: " + amount);
        } else {
            System.out.println("Insufficient balance or invalid withdrawal amount.");
        }
    }

    // Method to display depositor's name
    @Override
    public String displayName() {
        return depositorName;
    }

    // Method to display balance
    @Override
    public double displayBalance() {
        return balance;
    }

    // Method to get account details
    @Override
    public String getAccountDetails() {
        return "Account Number: " + accountNumber + "\n" +
                "Depositor Name: " + depositorName + "\n" +
                "Type of Account: " + typeOfAccount + "\n" +
                "Balance: " + balance;
    }

    // Method to get interest rate based on account type and bank
    @Override
    public double getInterestRate() {
        if (typeOfAccount.equalsIgnoreCase("Savings")) {
            return 0.01; // 1%
        } else if (typeOfAccount.equalsIgnoreCase("FixedDeposit")) {
            if (accountNumber.startsWith("AGR")) {
                return 0.03; // Agrani Bank
            } else if (accountNumber.startsWith("JAN")) {
                return 0.025; // Janata Bank
            } else if (accountNumber.startsWith("SON")) {
                return 0.02; // Sonali Bank
            }
        }
        return 0.0; // Default interest rate
    }

    public static void main(String[] args) {
        // Example usage
        BankAccount account1 = new BankAccount("John Doe", "Savings", "AGR123456", 1000);
        account1.depositAmount(500);
        account1.withdrawAmount(200);
        System.out.println(account1.getAccountDetails());
        System.out.println("Interest Rate: " + account1.getInterestRate() * 100 + "%");
    }
}
