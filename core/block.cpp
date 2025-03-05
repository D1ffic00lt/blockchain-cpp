#include "block.h"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>
#include <string>

Block::Block(const std::initializer_list<Transaction> transactions)
    : _transactions(transactions), _nonce(0) {
    // Initialize _hashPrev and _timestamp as needed
    computeHash();
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

void Block::computeHash() {
    std::stringstream ss;
    ss << _hashPrev << _timestamp << _nonce;
    for (const auto& transaction : _transactions) {
        ss << transaction.getDetails();
    }

    std::string data = ss.str();
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(data.c_str()), data.size(), hash);

    std::stringstream hashString;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        hashString << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    _hashCurrent = hashString.str();
}

void Block::mineBlock(int difficulty) {
    std::string target(difficulty, '0');
    do {
        _nonce++;
        computeHash();
    } while (_hashCurrent.substr(0, difficulty) != target);
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
