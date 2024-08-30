#include "block/Block.hpp"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <openssl/sha.h>

Block::Block(const std::string& data, const std::string& previousHash)
    : data(data), previousHash(previousHash), timestamp(std::time(nullptr)), nonce(0) {
    hash = calculateHash();
}

std::string Block::getHash() const {
    return hash;
}

std::string Block::getPreviousHash() const {
    return previousHash;
}

std::string Block::getData() const {
    return data;
}

time_t Block::getTimestamp() const {
    return timestamp;
}

int Block::getNonce() const {
    return nonce;
}

std::string Block::calculateHash() const {
    std::stringstream ss;
    ss << previousHash << timestamp << data << nonce;
    std::string input = ss.str();

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)input.c_str(), input.size(), hash);

    std::stringstream hashStream;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        hashStream << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return hashStream.str();
}

void Block::mineBlock(int difficulty) {
    std::string target(difficulty, '0');
    do {
        nonce++;
        hash = calculateHash();
    } while (hash.substr(0, difficulty) != target);

    std::cout << "Block mined: " << hash << std::endl;
}
