#ifndef BLOCK_H
#define BLOCK_H

#include <initializer_list>
#include <deque>
#include <unordered_map>
#include <string>
#include "transaction.h"

typedef std::deque<Transaction> Transactions;

class BlockInterface {
public:
    virtual ~BlockInterface() = default;
    virtual const Transactions& getTransactions() const = 0;
    virtual const std::string& getPrevHash() const = 0;
    virtual const std::string& getCurrentHash() const = 0;
};

class Block : public BlockInterface {
public:
    Block(std::initializer_list<Transaction> transactions);
    const Transactions& getTransactions() const override;
    const std::string& getPrevHash() const override;
    const std::string& getCurrentHash() const override;

    void mineBlock(int difficulty);
    ~Block() = default;

private:
    void computeHash();
    Transactions _transactions;
    std::string _hashPrev;
    std::string _hashCurrent;
    std::string _timestamp;
    int _nonce;
};

class NullBlock : public BlockInterface {
public:
    NullBlock();
    const Transactions& getTransactions() const override;
    const std::string& getPrevHash() const override;
    const std::string& getCurrentHash() const override;

private:
    Transactions _transactions;
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
    std::deque<Block> _blocks;
};

#endif //BLOCK_H
