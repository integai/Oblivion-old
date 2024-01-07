#ifndef BLOCK_H
#define BLOCK_H

#include <string>

class Block {
public:
    std::string sPrevHash;
    std::string sHash;
    int nNonce = -1;
    std::string sData;

    Block(std::string sDataIn, std::string sPrevHashIn);

    std::string GetHash();
    std::string CalculateHash() const;
};

#endif
