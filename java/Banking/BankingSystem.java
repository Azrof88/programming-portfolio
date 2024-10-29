package Banking;

import java.util.Scanner;

public class BankingSystem {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter Depositor Name:");
        String name = scanner.nextLine();

        System.out.println("Choose Bank (Agrani/Sonali/Janata):");
        String bankChoice = scanner.nextLine();
        Bank bank = null;

        switch (bankChoice.toLowerCase()) {
            case "agrani":
                bank = new AgraniBank();
                break;
            case "sonali":
                bank = new SonaliBank();
                break;
            case "janata":
                bank = new JanataBank();
                break;
            default:
                System.out.println("Invalid bank choice.");
                return;
        }

        System.out.println("Enter Account Type (Savings/FixedDeposit):");
        String accountType = scanner.nextLine();
        System.out.println("Enter Account Number:");
        String accountNumber = scanner.nextLine();
        System.out.println("Enter Initial Balance:");
        double initialBalance = scanner.nextDouble();

        BankAccount account = new BankAccount(name, accountType, accountNumber, initialBalance, bank);

        account.displayAccountDetails();

        System.out.println("Enter amount to deposit:");
        double depositAmount = scanner.nextDouble();
        account.depositAmount(depositAmount);
        account.displayAccountDetails();

        System.out.println("Enter amount to withdraw:");
        double withdrawAmount = scanner.nextDouble();
        account.withdrawAmount(withdrawAmount);
        account.displayAccountDetails();

        System.out.println("Enter number of years to calculate interest:");
        int years = scanner.nextInt();
        double interest = account.calculateInterest(years);
        System.out.println("Interest earned over " + years + " years: " + interest);

        scanner.close();
    }

}
