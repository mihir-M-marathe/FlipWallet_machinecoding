//
// Created by mihir on 9/16/2024.
//

#include "Wallet.h"
#include <iostream>
#include <unordered_map>

void Wallet::registerUser(const std::string &name) {
  for (const auto &user : users) {
    if (user.getUsername() == name) {
      // add exception here
      std::cout << "User " << name << " is already registered." << std::endl;
      return;
    }
  }
  users.emplace_back(name);
  transactionCount[name] = 0;
  cashbackRecords[name] = 0;
  std::cout << "User " << name << " is registered" << std::endl;
}

// void Wallet::topUpWallet(const std::string &userName, const std::string &method, double amount) {
//   // add exception here
//   if (amount <= 0) {
//     std::cout << "Invalid top-up amount." << std::endl;
//     return;
//   }
//   for (const auto &user : users) {
//     if (user.getUsername() == userName) {
//       user.addToBalance(amount);
//       std::cout << userName << "'s wallet has credit with " << amount << " Rs successfully" << std::endl;
//       return;
//     }
//   }
//   std::cout << "User " << userName << " is not registered" << std::endl;
// }

void Wallet::topUpWallet(const std::string &userName, const std::string &method, double amount) {
  if (amount <= 0) {
    std::cout << "Invalid top-up amount." << std::endl;
    return;
  }

  for (auto &user : users) {  // Use non-const reference here
    if (user.getUsername() == userName) {
      user.addToBalance(amount);  // Calls non-const method
      std::cout << userName << "'s wallet has been credited with " << amount << " Rs successfully" << std::endl;

      // Update transaction count and apply cashback if applicable
      transactionCount[userName]++;
      applyCashback(userName);
      return;
    }
  }
  std::cout << "User " << userName << " is not registered" << std::endl;
}



void Wallet::sendMoney(const std::string &fromUser, const std::string &toUser, double amount) {
  if (amount <= 0) {
    std::cout << "Invalid amount. Should be greater than 0" << std::endl;
  }
  User *sender = nullptr;
  User *receiver = nullptr;

  for (auto &user : users) {
    if (user.getUsername() == fromUser) {
      sender = &user;
    }
    if (user.getUsername() == toUser) {
      receiver = &user;
    }
  }
    if (!sender || !receiver) {
      std::cout << "User/Receiver not found." << std::endl;
      return;
    }

    if (!sender->hasSufficientBalance(amount)) {
      std::cout << fromUser << " doesn’t have sufficient amount to transfer " << amount << " Rs" << std::endl;
      return;
    }

  sender->subtractFromBalance(amount);
  receiver->addToBalance(amount);
  sender->addTransaction(Transaction(amount, sender->getUsername(), receiver->getUsername(), true));
  receiver->addTransaction(Transaction(amount, sender->getUsername(), receiver->getUsername(), false));

  transactionCount[fromUser]++;

  if (transactionCount[fromUser] % 5 == 0) {
    std::cout << fromUser << " has transferred " << amount << " Rs amount to " << toUser << " and get cashback of 10 Rs" << std::endl;
    sender->addToBalance(10); // Cashback logic
  } else {
    std::cout << fromUser << " has transferred " << amount << " Rs amount to " << toUser << std::endl;
  }
}

void Wallet::fetchBalance(const std::string &userName) const {
  for (const auto &user : users) {
    if (user.getUsername() == userName) {
      std::cout << userName << "’s wallet has " << user.getWalletBalance() << " Rs amount" << std::endl;
      return;
    }
  }
  std::cout << "User " << userName << " is not registered" << std::endl;
}

std::vector<Transaction> Wallet::getTransactions(const std::string &userName, const std::string &filter, const std::string &sorter){
  for (auto &user : users) {
    if (user.getUsername() == userName) {
      return user.getTransactions(filter, sorter);
    }
  }
  std::cout << "User " << userName << " is not registered" << std::endl;
  return {};
}

void Wallet::applyCashback(const std::string &userName) {
  // Get the number of transactions for the user
  int transactionCountForUser = transactionCount[userName];

  // Criteria: Cashback after every 5 transactions
  if (transactionCountForUser > 5) {
    // Apply cashback
    int multiplierForUser = transactionCountForUser % 5;
    for (auto &user : users) {
      if (user.getUsername() == userName) {
        user.addToBalance(cashbackAmountPer5Transactions * multiplierForUser);
        cashbackRecords[userName] += cashbackAmountPer5Transactions * multiplierForUser;
        std::cout << "Cashback of " << cashbackAmountPer5Transactions * multiplierForUser << " Rs applied to " << userName << std::endl;
        return;
      }
    }
  }
}

double Wallet::getCashbackAmount(const std::string &userName) const {
  auto it = cashbackRecords.find(userName);
  if (it != cashbackRecords.end()) {
    return it->second;
  } else {
    std::cout << "User " << userName << " is not registered or has no cashback records." << std::endl;
    return 0.0;
  }
}