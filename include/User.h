//
// Created by mihir on 9/16/2024.
//

#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Transaction.h"

class User {

  private:
    std::string userName;
//    std::string password;
//    std::string userId;
    double walletBalance{};
    std::vector<Transaction> transactions;

  public:
    explicit User(std::string name);

    explicit User(std::string &name);

    [[nodiscard]] std::string getUsername() const;
    [[nodiscard]] double getWalletBalance() const;

    // Method to add amount to the user's balance (not const)
    void addToBalance(double amount);
    void subtractFromBalance(double amount);

    void addTransaction(const Transaction &transaction);
    std::vector<Transaction> getTransactions(const std::string &filter, const std::string &sorter);

    bool hasSufficientBalance(double amount) const;
};

#endif //USER_H
