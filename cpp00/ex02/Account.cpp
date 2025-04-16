#include "Account.hpp"
#include <iomanip>
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts++),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0)
{
    _displayTimestamp();
    _totalAmount += initial_deposit;
    std::cout << "index:" << _accountIndex
            << ";amount:" << _amount
            << ";created" << std::endl;
};

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
};

void Account::_displayTimestamp(void) {
    std::time_t t = std::time(nullptr);

    std::tm *tmb = std::localtime(&t);
    std::cout << std::put_time(tmb, "[%Y%m%d_%H%M%S] ");
}

int Account::getNbAccounts(void) { return (_nbAccounts); }

int Account::getTotalAmount(void) { return (_totalAmount); }

int Account::getNbDeposits(void) { return (_totalNbDeposits); }

int Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); }

void Account::displayAccountsInfos(void) {
    _displayTimestamp();

    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

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

    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}