#include "blockchain/Blockchain.hpp"
#include <iostream>

int main() {
    Blockchain blockchain(4);

    blockchain.addBlock("Block 1 Data: bomb is coming at 12 o'clock at 101.1231, 3.2131");

    std::cout << "Blockchain created and block added." << std::endl;

    blockchain.printChain();

    return 0;
}
