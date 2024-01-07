#include "block.h"
#include "blockchain.h"
#include <iostream>
using namespace std;

int main() {
    Blockchain myBlockchain;
    Block genesisBlock = myBlockchain.createGenesisBlock();
    myBlockchain.addBlock(genesisBlock);
    cout << "Genesis block created and added to blockchain. Hash: " << genesisBlock.GetHash() << endl;
    return 0;
}

