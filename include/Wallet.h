//
// Created by mihir on 9/16/2024.
//

#ifndef WALLET_H
#define WALLET_H

#include "User.h"
#include <unordered_map>

class Wallet {

  private:
    std::vector<User> users;
    std::unordered_map<std::string, int> transactionCount;
    // For example, store cashback amounts per user
    std::unordered_map<std::string, double> cashbackRecords;
    double cashbackAmountPer5Transactions = 10.0; // Example cashback amount

  public:
    void registerUser(const std::string &name);
    void topUpWallet(const std::string &userName, const std::string &method, double amount);
    void sendMoney(const std::string &fromUser, const std::string &toUser, double amount);
    void fetchBalance(const std::string &userName) const;
    std::vector<Transaction> getTransactions(const std::string &userName, const std::string &filter, const std::string &sorter);
    void checkForCashback(const std::string &userName);
    //double getCashbackAmount(const std::string &userName);
    void applyCashback(const std::string &userName);

    double getCashbackAmount(const std::string &userName) const;

    // double getCashBack(const std::string &userName) const;
};

#endif //WALLET_H
