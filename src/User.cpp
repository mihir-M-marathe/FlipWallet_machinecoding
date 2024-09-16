//
// Created by mihir on 9/16/2024.
//

#include "User.h"
#include <string>
#include <algorithm>
#include <utility>

User::User(std::string  name) : userName(std::move(name)), walletBalance(0.0) {
    // Initialize the user with the given name and set the balance to zero
    // You can add additional initialization logic if required
};

std::string User::getUsername() const{
    return userName;
}

double User::getWalletBalance() const{
    return walletBalance;
}

void User::addToBalance(const double amount){
    walletBalance += amount;
}

void User::subtractFromBalance(double amount){
    walletBalance -= amount;
}

bool User::hasSufficientBalance(double amount) const{
    return walletBalance >= amount;
}

void User::addTransaction(const Transaction &transaction){
      transactions.push_back(transaction);
}

std::vector<Transaction> User::getTransactions(const std::string &filter, const std::string &sorter){
    std::vector<Transaction> result = transactions;
    if (filter == "send") {
        result.erase(std::remove_if(result.begin(), result.end(), [](const Transaction &t) { return !t.isSendTransaction(); }), result.end());
    } else if (filter == "receive") {
        result.erase(std::remove_if(result.begin(), result.end(), [](const Transaction &t) { return t.isSendTransaction(); }), result.end());
    }

    if (sorter == "amount") {
        std::sort(result.begin(), result.end(), [](const Transaction &a, const Transaction &b) { return a.getAmount() < b.getAmount(); });
    } else if (sorter == "time") {
        std::sort(result.begin(), result.end(), [](const Transaction &a, const Transaction &b) { return a.getTimestamp() < b.getTimestamp(); });
    }
    return result;
}