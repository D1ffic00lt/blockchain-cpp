#include "block.h"


Block::Block(const std::initializer_list<Transaction> transactions) : _transactions(transactions) {
}

bool Block::approveBlock() {
    for (const Transaction &transaction: _transactions) {
        Wallet &from = (transaction.getSender());
    }
}

void BlockChain::addBlock(const Block &block) {
    _blocks.push_back(block);
}

void BlockChain::addWallet(const Wallet &wallet) {
    _wallets[wallet.getAddress()] = wallet;
}

Wallet BlockChain::getWallet(const std::string &address) {
    if (!_wallets.contains(address)) {
        Wallet wallet(address);
        addWallet(wallet);
        return wallet;
    }
    return _wallets.at(address);
}
