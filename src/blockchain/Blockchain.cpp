#include "blockchain/Blockchain.hpp"
#include <iostream>

Blockchain::Blockchain(int difficulty) : difficulty(difficulty) {
    chain.push_back(createGenesisBlock());
}

void Blockchain::addBlock(const std::string& data) {
    Block newBlock(data, chain.back().getHash());
    newBlock.mineBlock(difficulty);
    chain.push_back(newBlock);
}

const std::vector<Block>& Blockchain::getChain() const {
    return chain;
}

Block Blockchain::createGenesisBlock() const {
    return Block("Genesis Block", "0");
}

void Blockchain::printChain() const {
    for (const auto& block : chain) {
        std::cout << "Block Hash: " << block.getHash() << std::endl;
        std::cout << "Previous Hash: " << block.getPreviousHash() << std::endl;
        std::cout << "Data: " << block.getData() << std::endl;
        std::cout << "Timestamp: " << block.getTimestamp() << std::endl;
        std::cout << "Nonce: " << block.getNonce() << std::endl;
        std::cout << "-------------------------" << std::endl;
    }
}
