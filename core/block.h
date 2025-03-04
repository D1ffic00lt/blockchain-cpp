#ifndef BLOCK_H
#define BLOCK_H

#include <initializer_list>
#include <deque>
#include <unordered_map>
#include "transaction.h"

typedef std::deque<Transaction> Transactions;


class BlockInterface {
public:
    const Transactions& getTransactions() const;

};

class Block : public BlockInterface {
public:
    Block(std::initializer_list<Transaction> transactions);
    const Transactions& getTransactions() const;

    ~Block() = default;

private:

    Transactions _transactions;
    std::string _hashPrev;
    std::string hashCurrent;


};

class NullBlock : public BlockInterface {
    NullBlock();
private:
    void* _hashPrev;
    std::string _hashCurrent;
};


class BlockChain {
public:
    BlockChain() = default;
    ~BlockChain() = default;

    void addBlock(const Block &block);

    void addWallet(Wallet *wallet);
    bool approveBlock(Block& block);

    const Wallet* resolveWallet(const std::string &address, double amount = 0.0);

private:
    std::unordered_map<std::string, Wallet*> _wallets;
    std::deque<BlockInterface> _blocks;
};

#endif //BLOCK_H
