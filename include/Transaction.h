// Created by mihir on 9/16/2024.


#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>

class Transaction {
  private:
    double amount;
    std::string sender;
    std::string receiver;
    std::time_t timestamp;
    bool isSend;

  public:
    Transaction(double amount, const std::string &sender, const std::string &receiver, bool isSend);

    double getAmount() const;
    std::string getSender() const;
    std::string getReceiver() const;
    std::time_t getTimestamp() const;
    bool isSendTransaction() const;
};

#endif //TRANSACTION_H
