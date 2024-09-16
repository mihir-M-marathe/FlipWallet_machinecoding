//
// Created by mihir on 9/16/2024.
//

#include <iostream>
#include "Wallet.h"

int main() {
    Wallet flipkartWallet;

    flipkartWallet.fetchBalance("Bob");
    flipkartWallet.registerUser("Bob");
    flipkartWallet.topUpWallet("Bob", "CC", 1000);
    flipkartWallet.topUpWallet("Bob", "UPI", 100);
    flipkartWallet.fetchBalance("Bob");

    flipkartWallet.registerUser("Alice");
    flipkartWallet.topUpWallet("Alice", "CC", 100);
    flipkartWallet.fetchBalance("Alice");

    flipkartWallet.sendMoney("Bob", "Alice", 1250);
    flipkartWallet.sendMoney("Bob", "Alice", 250);
    flipkartWallet.sendMoney("Alice", "Bob", 50);

    flipkartWallet.fetchBalance("Bob");
    flipkartWallet.fetchBalance("Alice");

    for (const auto &t : flipkartWallet.getTransactions("Bob", "send", "amount")) {
        std::cout << t.getSender() << "-> " << t.getReceiver() << " : " << t.getAmount() << " Rs" << std::endl;
    }

    for (const auto &t : flipkartWallet.getTransactions("Bob", "receive", "time")) {
        std::cout << t.getSender() << "-> " << t.getReceiver() << " : " << t.getAmount() << " Rs" << std::endl;
    }

    // BONUS
    flipkartWallet.sendMoney("Bob", "Alice", 100);
    std::cout << "Bob got total cashback of " << flipkartWallet.getCashbackAmount("Bob") << " Rs" << std::endl;

    flipkartWallet.fetchBalance("Bob");
    flipkartWallet.fetchBalance("Alice");

    for (const auto &t : flipkartWallet.getTransactions("Bob", "send", "amount")) {
        std::cout << t.getSender() << "-> " << t.getReceiver() << " : " << t.getAmount() << " Rs" << std::endl;
    }

    for (const auto &t : flipkartWallet.getTransactions("Bob", "receive", "time")) {
        std::cout << t.getSender() << "-> " << t.getReceiver() << " : " << t.getAmount() << " Rs" << std::endl;
    }

    return 0;
}
