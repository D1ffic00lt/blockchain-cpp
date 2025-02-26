#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

enum TransactionType {
    SEND,
    RECEIVE
};

class Transaction {
public:
    Transaction(const std::string &from, const std::string &to, double amount);

    ~Transaction() = default;

    [[nodiscard]] std::string getSender() const;
    [[nodiscard]] std::string getReceiver() const;
    [[nodiscard]] double getAmount() const;

private:
    std::string _from;
    std::string _to;
    double _amount;
};

class Wallet {
public:
    explicit Wallet(const std::string &address, double balance = 0);

    ~Wallet() = default;

    [[nodiscard]] double getBalance() const;

    [[nodiscard]] Transaction makeTransfer(const std::string &to, double amount) const;

    bool updateAmount(double amount, TransactionType type);

    [[nodiscard]] std::string getAddress() const;

private:
    std::string _address;
    double _balance;
};


#endif //TRANSACTION_H
