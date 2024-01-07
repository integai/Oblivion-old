#include <string>
#include <vector>
#include "crypto/sha256.h"
using namespace std;

class Block {
public:
    std::string sPrevHash;
    std::string sHash;
    int nNonce = -1;
    std::string sData;
    std::string sExtraData;
    std::string sMemo;

    Block(std::string sDataIn, std::string sPrevHashIn, std::string sExtraDataIn = "", std::string sMemoIn = "");
    Block createGenesisBlock();

    std::string GetHash();
    std::string GetExtraData() const;
    std::string GetMemo() const;
    std::string CalculateHash() const;
};

Block::Block(std::string sDataIn, std::string sPrevHashIn, std::string sExtraDataIn, std::string sMemoIn) {
    this->sData = sDataIn;
    this->sPrevHash = sPrevHashIn;
    this->sExtraData = sExtraDataIn;
    this->sMemo = sMemoIn;
    this->sHash = CalculateHash();
}


string Block::CalculateHash() const {
    return generateSHA256(sData + sPrevHash + std::to_string(nNonce) + sExtraData + sMemo); // Added memo to hash calculation
}

string Block::GetHash() {
    return this->CalculateHash();
}

string Block::GetExtraData() const {
    return this->sExtraData;
}

string Block::GetMemo() const {
    return this->sMemo;
}
