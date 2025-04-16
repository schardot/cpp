#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::makeDeposit(int deposit) {
    _displayTimestamp();

    std::cout << "index:" << _accountIndex
                << ";p_amount:" << _amount;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits ++;
    _totalNbDeposits ++;
    std::cout << ";deposit:" << deposit
                << ";amount:" << _amount
                << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    bool allowed = true;

    if (_amount - withdrawal < 0)
        allowed = false;

    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";withdrawal:";
    if (allowed == false) {
        std::cout << "refused" << std::endl;
        return (allowed);
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals ++;
    _totalNbWithdrawals ++;
    std::cout << withdrawal
              << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (allowed);
}

int Account::checkAmount(void) const {
    return (_amount);
}

void Account::displayStatus(void) const {
    _displayTimestamp();

    std::cout << "index:" << Account::getAccountIndex()
                << ";amount:" << Account::getAmount()
                << ";deposits:" << Account::getNbDeposits()
                << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}