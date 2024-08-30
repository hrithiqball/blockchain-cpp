#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP

#include <vector>
#include "block/Block.hpp"

class Blockchain {
public:
    Blockchain(int difficulty);
    void addBlock(const std::string& data);
    const std::vector<Block>& getChain() const;
    void printChain() const;

private:
    std::vector<Block> chain;
    int difficulty;

    Block createGenesisBlock() const;
};

#endif // BLOCKCHAIN_HPP
