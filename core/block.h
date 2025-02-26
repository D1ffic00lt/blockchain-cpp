#ifndef BLOCK_H
#define BLOCK_H

#include <initializer_list>
#include <deque>
#include <unordered_map>
#include "transaction.h"

class Block {
public:
    Block(std::initializer_list<Transaction> transactions);

    ~Block() = default;

    bool approveBlock();

private:
    std::deque<Transaction> _transactions;
};

class BlockChain {
public:
    BlockChain() = default;

    ~BlockChain() = default;

    void addBlock(const Block &block);

    void addWallet(const Wallet &wallet);

    Wallet getWallet(const std::string &address);

private:
    std::unordered_map<std::string, Wallet> _wallets;
    std::deque<Block> _blocks;
};
#endif //BLOCK_H
