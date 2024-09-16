//
// Created by Mihir on 9/16/2024.
//

#include "Transaction.h"

Transaction::Transaction(double amt, const std::string &sndr, const std::string &rcvr, bool send)
    : amount(amt), sender(sndr), receiver(rcvr), isSend(send) {
    timestamp = std::time(nullptr);
}

double Transaction::getAmount() const {
    return amount;
}

std::time_t Transaction::getTimestamp() const {
    return timestamp;
}

bool Transaction::isSendTransaction() const {
    return isSend;
}

std::string Transaction::getSender() const {
    return sender;
}

std::string Transaction::getReceiver() const {
    return receiver;
}