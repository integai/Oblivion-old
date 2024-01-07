#include <vector>
#include <ctime>
#include "block.h"
#include <iostream>
using namespace std;

class Blockchain {
public:
    Blockchain();
    int difficulty;
    vector<Block> chain;
    Block createGenesisBlock() const;
    Block getLatestBlock() const;
    bool isChainValid() const;
    void addBlock(Block &newBlock);
    void MineBlock(Block &newBlock, int difficulty);
};

Blockchain::Blockchain() {
    chain.push_back(createGenesisBlock());
    difficulty = 4;
}

Block Blockchain::createGenesisBlock() const {
    return Block("Genesis Block", "0");
}

Block Blockchain::getLatestBlock() const {
    return chain.back();
}

bool Blockchain::isChainValid() const {
    for(int i = 1; i < chain.size(); i++) {
        Block currentBlock = chain[i];
        Block previousBlock = chain[i - 1];

        if(currentBlock.GetHash() != currentBlock.CalculateHash()) {
            return false;
        }

        if(currentBlock.sPrevHash != previousBlock.GetHash()) {
            return false;
        }
    }

    return true;
}

void Blockchain::MineBlock(Block &newBlock, int difficulty) {
    string target = string(difficulty, '0');
    while (newBlock.GetHash().substr(0, difficulty) != target) {
        newBlock.nNonce++;
        newBlock.sHash = newBlock.CalculateHash();
    }
    cout << "Block mined: " << newBlock.GetHash() << endl;
}

void Blockchain::addBlock(Block &newBlock) {
    newBlock.sPrevHash = getLatestBlock().GetHash();
    MineBlock(newBlock, difficulty);
    chain.push_back(newBlock);
}