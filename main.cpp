#include <iostream>
#include <vector>
#include <algorithm>
#include "customer.h"
#include "logger.h"
#include "crypto_utils.h"

void printMenu()
{
    std::cout << "\n=== Customer Manager ===\n"
              << "1. Додати покупця\n"
              << "2. Показати всіх (алфавіт)\n"
              << "3. Показати картки у діапазоні\n"
              << "4. Зберегти (шифр.)\n"
              << "5. Завантажити (шифр.)\n"
              << "0. Вихід\n> ";
}

int main()
{
    Logger log;
    std::vector<Customer> customers;

    int choice = -1;
    while (choice != 0) {
        printMenu();
        std::cin >> choice;

        try {
            if (choice == 1) {
                Customer c;
                std::cout << "Введіть: id surname name card(4) account(5)\n> ";
                if (std::cin >> c) {
                    customers.push_back(c);
                    log.log("Add: " + c.toString());
                }
            }
            else if (choice == 2) {
                std::sort(customers.begin(), customers.end());
                std::cout << "\n--- Список покупців (алфавіт) ---\n";
                for (const auto& c : customers) std::cout << c << '\n';
            }
            else if (choice == 3) {
                int low, high;
                std::cout << "Введіть діапазон [low high] 4-значних номерів картки:\n> ";
                std::cin >> low >> high;
                std::cout << "\n--- Покупці з карткою у діапазоні ---\n";
                for (const auto& c : customers)
                    if (c.cardNumber() >= low && c.cardNumber() <= high)
                        std::cout << c << '\n';
            }
            else if (choice == 4) {
                CryptoUtils::saveEncrypted("customers.dat", customers);
                std::cout << "Збережено у customers.dat\n";
                log.log("Saved encrypted file");
            }
            else if (choice == 5) {
                customers = CryptoUtils::loadEncrypted("customers.dat");
                std::cout << "Завантажено " << customers.size() << " запис(ів)\n";
                log.log("Loaded encrypted file");
            }
        }
        catch (const std::exception& ex) {
            std::cerr << "Помилка: " << ex.what() << '\n';
            log.log(std::string("Exception: ") + ex.what());
        }
    }
}
