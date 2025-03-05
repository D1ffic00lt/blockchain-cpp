#include "block.h"

Block::Block(const std::initializer_list<Transaction> transactions) : _transactions(transactions) {
}

const Transactions& Block::getTransactions() const {
    return _transactions;
}

const std::string& Block::getPrevHash() const {
    return _hashPrev;
}

const std::string& Block::getCurrentHash() const {
    return _hashCurrent;
}

NullBlock::NullBlock() : _hashPrev(nullptr) {
}

const Transactions& NullBlock::getTransactions() const {
    return _transactions;
}

const std::string& NullBlock::getPrevHash() const {
    static const std::string nullHash = "null";
    return nullHash;
}

const std::string& NullBlock::getCurrentHash() const {
    return _hashCurrent;
}

void BlockChain::addBlock(const Block &block) {
    _blocks.push_back(block);
}

void BlockChain::addWallet(Wallet *wallet) {
    _wallets[wallet->getAddress()] = wallet;
}

const Wallet* BlockChain::resolveWallet(const std::string &address, double amount) {
    if (_wallets.find(address) == _wallets.end()) {
        Wallet* wallet = new Wallet(address, amount);
        addWallet(wallet);
        return wallet;
    }
    return _wallets.at(address);
}



bool BlockChain::approveBlock(Block& block) {
    for (const Transaction &transaction: block.getTransactions()) {
        const Wallet* from = this->resolveWallet(transaction.getSender());
        const Wallet* to = this->resolveWallet(transaction.getReceiver());
        const double amount = transaction.getAmount();

    }
    return true;
}
