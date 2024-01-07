#include "../block.h"
#include "../blockchain.h"
#include <iostream>

bool isBlockValid(const Block& block, const Blockchain& blockchain) {
    const Block& latestBlock = blockchain.getLatestBlock();

    if (block.GetHash() != block.CalculateHash()) {
        std::cerr << "Block hash is not valid.\n";
        return false;
    }

    if (latestBlock.GetHash() != block.GetPrevHash() && block.GetPrevHash() != "0") {
        std::cerr << "Block does not continue from the latest block in the blockchain.\n";
        return false;
    }

    return true;
}

