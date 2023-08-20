// Cruz Matthew  7/30/23  Airgead Banking Investment Calculator

#include <iostream>
#include <iomanip>

void printTableHeader(bool isYearlyReport) {
    if (isYearlyReport) {
        std::cout << std::setw(11) << "Year" << " | ";
        std::cout << std::setw(21) << "Year-end Balance" << " | ";
        std::cout << std::setw(24) << "Year-end Earned Interest" << std::endl;
        std::cout << "---------------------------------------------"
            << "-------------------------" << std::endl;
    }
    else {
        std::cout << std::setw(5) << "Month" << " | ";
        std::cout << std::setw(15) << "Opening Amount" << " | ";
        std::cout << std::setw(15) << "Deposited Amount" << " | ";
        std::cout << std::setw(10) << "Total $" << " | ";
        std::cout << std::setw(10) << "Interest $" << " | ";
        std::cout << std::setw(15) << "Closing Balance" << std::endl;
        std::cout << "--------------------------------------------------------------------------------------" << std::endl;
    }
}

void calculateYearlyInvestment(double initialInvestment, double monthlyDeposit, double annualInterest, int numberOfYears) {
    double openingAmount = initialInvestment;
    double monthlyInterestRate = annualInterest / 12 / 100;

    // Report 1: Year-end balances and earned interest without additional monthly deposits
    std::cout << std::endl;
    std::cout << "      Balance and Interest Without Additional Month Deposits" << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;
    printTableHeader(true);
    for (int year = 1; year <= numberOfYears; ++year) {
        double interest = openingAmount * monthlyInterestRate * 12;
        double closingBalance = openingAmount + interest;
        std::cout << std::setw(8) << year << " | ";
        std::cout << "$" << std::setw(17) << std::fixed << std::setprecision(2) << closingBalance << " | ";
        std::cout << "$" << std::setw(20) << std::fixed << std::setprecision(2) << interest << std::endl;
        openingAmount = closingBalance;
    }

    // Reset openingAmount to initialInvestment for Report 2
    openingAmount = initialInvestment;

    // Report 2: Year-end balances and earned interest with additional monthly deposits
    std::cout << std::endl;
    std::cout << "      Balance and Interest With Additional Monthly Deposits " << std::fixed << std::setprecision(2) << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;
    printTableHeader(true);
    for (int year = 1; year <= numberOfYears; ++year) {
        double total = openingAmount + monthlyDeposit;
        double interest = total * monthlyInterestRate * 12;
        double closingBalance = total + interest;
        std::cout << std::setw(8) << year << " | ";
        std::cout << "$" << std::setw(17) << std::fixed << std::setprecision(2) << closingBalance << " | ";
        std::cout << "$" << std::setw(20) << std::fixed << std::setprecision(2) << interest << std::endl;
        openingAmount = closingBalance;
    }

    // Prompt user to continue to the next report
    std::cout << "\nPress Enter To Continue To Monthly Investments" << std::endl;
    std::cin.ignore();
    std::cin.get();
    std::cout << "          Investments Per Month For Total Years " << std::fixed << std::setprecision(2) << std::endl;
    std::cout << "--------------------------------------------------------------------------------------" << std::endl;
}

void calculateMonthlyInvestment(double initialInvestment, double monthlyDeposit, double annualInterest, int numberOfYears) {
    double openingAmount = initialInvestment;
    double monthlyInterestRate = annualInterest / 12 / 100;

    printTableHeader(false);

    for (int month = 1; month <= numberOfYears * 12; ++month) {
        double interest = openingAmount * monthlyInterestRate;
        double closingBalance = openingAmount + interest + monthlyDeposit;
        std::cout << std::setw(5) << month << " | ";
        std::cout << std::setw(15) << openingAmount << " | ";
        std::cout << std::setw(15) << monthlyDeposit << " | ";
        std::cout << "$" << std::setw(9) << openingAmount + monthlyDeposit << " | ";
        std::cout << "$" << std::setw(9) << interest << " | ";
        std::cout << std::setw(15) << closingBalance << std::endl;
        openingAmount = closingBalance;
    }
}

int main() {
    std::cout << "**********************************************************" << std::endl;
    std::cout << "********* Airgead Banking Investment Calculator **********" << std::endl;

    double initialInvestment, monthlyDeposit, annualInterest;
    int numberOfYears;

    std::cout << "Enter Initial Investment Amount : ";
    std::cin >> initialInvestment;
    std::cout << "Enter Monthly Deposit: ";
    std::cin >> monthlyDeposit;
    std::cout << "Enter Annual Interest (Compounded) (e.g., 5 for 5%): ";
    std::cin >> annualInterest;
    std::cout << "Enter Number of Years: ";
    std::cin >> numberOfYears;

    calculateYearlyInvestment(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);

    calculateMonthlyInvestment(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);

    return 0;
}
