#include <iostream>
#include "core/src/block.h"
#include "core/src/transaction.h"

int main(int argc, char *argv[]) {
    Block block({Transaction("Alice", "Bob", 10.0)});
    BlockChain blockchain;
    blockchain.addBlock(block);

    std::cout << "Initial block added to the blockchain." << std::endl;
    const Wallet* alice = blockchain.resolveWallet("Alice", 15.0);
    const Wallet* bob = blockchain.resolveWallet("Bob");

    if (alice && bob) {
        std::cout << "Wallets for Alice and Bob resolved successfully." << std::endl;
    } else {
        std::cout << "Failed to resolve wallets for Alice or Bob." << std::endl;
        return 1;
    }
    Transaction transaction = alice->makeTransfer("Bob", 5.0);
    blockchain.addBlock(Block({transaction}));

    std::cout << "Transaction from Alice to Bob added to the blockchain." << std::endl;
    return 0;
}
