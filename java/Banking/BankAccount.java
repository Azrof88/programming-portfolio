package Banking;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class BankAccount {
    private String depositorName;
    private String typeOfAccount;
    private String accountNumber;
    private double balance;
    private Bank bank;

    public BankAccount(String depositorName, String typeOfAccount, String accountNumber, double initialBalance,
            Bank bank) {
        this.depositorName = depositorName;
        this.typeOfAccount = typeOfAccount;
        this.accountNumber = accountNumber;
        this.balance = initialBalance >= 0 ? initialBalance : 0;
        this.bank = bank;
        saveAccountDetails();
    }

    public void depositAmount(double amount) {
        if (amount > 0) {
            balance += amount;
            updateAccountDetails();
        } else {
            System.out.println("Deposit amount must be positive.");
        }
    }

    public void withdrawAmount(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            updateAccountDetails();
        } else {
            System.out.println("Invalid withdrawal amount.");
        }
    }

    public void displayAccountDetails() {
        System.out.println("Depositor Name: " + depositorName);
        System.out.println("Account Type: " + typeOfAccount);
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Balance: " + balance);
    }

    public double calculateInterest(int years) {
        return balance * getInterestRate() * years;
    }

    private double getInterestRate() {
        return bank.getInterestRate(typeOfAccount);
    }

    private void saveAccountDetails() {
        try (BufferedWriter writer = new BufferedWriter(
                new FileWriter("E:\\programming-portfolio\\java\\Banking\\" + accountNumber + "_"
                        + bank.getClass().getSimpleName() + ".txt"))) {
            writer.write("Depositor Name: " + depositorName);
            writer.newLine();
            writer.write("Account Type: " + typeOfAccount);
            writer.newLine();
            writer.write("Account Number: " + accountNumber);
            writer.newLine();
            writer.write("Balance: " + balance);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void updateAccountDetails() {
        saveAccountDetails(); // Update the file with new balance
    }

}
