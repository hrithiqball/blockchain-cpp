#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>
#include <ctime>

class Block {
public:
    Block(const std::string& data, const std::string& previousHash);

    std::string getHash() const;
    std::string getPreviousHash() const;
    std::string getData() const;
    time_t getTimestamp() const;
    int getNonce() const;
    
    void mineBlock(int difficulty);

private:
    std::string hash;
    std::string previousHash;
    std::string data;
    time_t timestamp;
    int nonce;

    std::string calculateHash() const;
};

#endif // BLOCK_HPP
