#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "Block.h"

class Blockchain {
public:
    Blockchain();

private:
    int difficulty;
    std::vector<Block> chain;

    Block createGenesisBlock() const;
    Block getLatestBlock() const;
    bool isChainValid() const;
    void addBlock(Block newBlock);
    void MineBlock(Block &newBlock, int difficulty);
};

#endif
