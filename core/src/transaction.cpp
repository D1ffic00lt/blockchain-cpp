#include "transaction.h"

Transaction::Transaction(const std::string &from, const std::string &to, const double amount) : _from(from), _to(to),
                                                                                                _amount(amount)
{
}

Transaction Wallet::makeTransfer(const std::string &to, const double amount) const
{
    if (amount > 0 && amount <= _balance)
    {
        Transaction transaction(_address, to, amount);
        return transaction;
    }
    throw std::runtime_error("Invalid amount");
}

std::string Transaction::getSender() const
{
    return this->_from;
}

std::string Transaction::getReceiver() const
{
    return this->_to;
}

double Transaction::getAmount() const
{
    return this->_amount;
}

double Wallet::getBalance() const
{
    return this->_balance;
}
std::string Transaction::getDetails() const {
    return _from + _to + std::to_string(_amount);
}

Wallet::Wallet(const std::string &address, const double balance) : _address(address), _balance(balance)
{
}


bool Wallet::updateAmount(const double amount, const TransactionType type)
{
    if (amount <= 0)
    {
        return false;
    }
    if (type == SEND)
    {
        if (_balance < amount)
        {
            return false;
        }
        _balance -= amount;
        return true;
    }
    _balance += amount;
    return true;
}

std::string Wallet::getAddress() const
{
    return _address;
}
