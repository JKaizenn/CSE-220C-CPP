//
//  main.cpp
//  Week01 Task - Account System
//
//  Created by Jessen Forbush on 1/6/25.
//

#include <iostream>
#include <string>

int main() {
    
    float balance = 0;
    std::string accountName = "";
    int idNumber = 0;
    int option;

    std::cout << "Welcome to your bank account management system!\n";
    
    // Prompt user for Account Name and ID.
    std::cout << "Please enter your account name and ID: \n";
    std::cin >> accountName >> idNumber;
    std::cout << "Your account name: " << accountName << std::endl;
    std::cout << "Your ID is: " << idNumber << std::endl;

    // Prompt user for account balance.
    std::cout << "Please enter your account balance: \n";
    std::cin >> balance;
    std::cout << "Current Balance: " << balance << std::endl;
    
    do {
        // Displaying menu options
        std::cout << "\nAccount Menu:\n";
        std::cout << "0. Quit Program\n";
        std::cout << "1. Display Account Information\n";
        std::cout << "2. Add a deposit to an account\n";
        std::cout << "3. Withdraw from an account\n";
        std::cout << "Enter your choice: ";
        std::cin >> option;  // Read menu choice
    
        if (std::cin.fail()) {
            std::cin.clear();  // Clear error flag
            std::cin.ignore(1000, '\n');  // Discard invalid input
            std::cout << "Invalid input! Please enter a valid number.\n";
            continue;
        }
    
        switch (option) {
            case 0:
                std::cout << "Exiting Program...\n";
                break;
    
            case 1:
                std::cout << "\nAccount Information:\n";
                std::cout << "Account Name: " << accountName << "\n";
                std::cout << "Account ID: " << idNumber << "\n";
                std::cout << "Balance: $" << balance << "\n";
                break;
    
            case 2: {
                float depositAmount;
                std::cout << "Enter deposit amount: ";
                std::cin >> depositAmount;
                if (std::cin.fail() || depositAmount < 0) {
                    std::cout << "Invalid deposit amount. Please enter a positive number.\n";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    continue;
                }
                balance += depositAmount;
                std::cout << "New balance: $" << balance << "\n";
                break;
            }
    
            case 3: {
                float withdrawAmount;
                std::cout << "Enter withdrawal amount: ";
                std::cin >> withdrawAmount;
                if (std::cin.fail() || withdrawAmount < 0) {
                    std::cout << "Invalid withdrawal amount. Please enter a positive number.\n";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    continue;
                }
                if (withdrawAmount <= balance) {
                    balance -= withdrawAmount;
                    std::cout << "Withdrawal successful! New balance: $" << balance << "\n";
                } else {
                    std::cout << "Insufficient funds! Current balance: $" << balance << "\n";
                }
                break;
            }
    
            default:
                std::cout << "Invalid option. Please select from 0 to 3.\n";
        }
    
    } while (option != 0);  // Continue until user chooses to quit
    
    return 0; // End Program
}
