#include "Block.h"
#include <iostream>
using namespace std;

int main() {
    Block testBlock("Test data", "Previous hash");
    cout << "Block created. Hash: " << testBlock.GetHash() << endl;
    return 0;
}

