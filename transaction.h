#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "block.h"
#include "blockchain.h"

class Transaction {
public:
    std::string senderKey;
    std::string receiverKey;
    int amount;
    std::string transactionHash;
    Blockchain* blockchain;


    Transaction(std::string sender, std::string receiver, int amount, Blockchain* blockchain);
    std::string getTransactionHash() const;
    bool isValid() const;
    void send();
};

#endif
