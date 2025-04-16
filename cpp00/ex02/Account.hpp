// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iomanip>
#include <iostream>
#include <ctime>

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;

    static int getNbAccounts(void) { return (_nbAccounts); }
    static int getTotalAmount(void) { return (_totalAmount); }
    static int getTotalNbDeposits(void) { return (_totalNbDeposits); }
    static int getTotalNbWithdrawals(void) { return (_totalNbWithdrawals); }
    static void	displayAccountsInfos( void ) {
        _displayTimestamp();

        std::cout << "accounts:" << _nbAccounts
                  << ";total:" << _totalAmount
                  << ";deposits:" << _totalNbDeposits
                  << ";withdrawals:" << _totalNbWithdrawals << std::endl;
    }

    Account(int initial_deposit)
        : _accountIndex(_nbAccounts++),
          _amount(initial_deposit),
          _nbDeposits(0),
          _nbWithdrawals(0)
    {
        _totalAmount += initial_deposit;
        _displayTimestamp();
        std::cout << "index:" << _accountIndex
                  << ";amount:" << _amount
                  << ";created" << std::endl;
    };
	~Account( void ){
        _displayTimestamp();
        std::cout << "index:" << _accountIndex
                  << ";amount:" << _amount
                  << ";closed" << std::endl;
    };

	void	makeDeposit( int deposit );
	bool	makeWithdrawal( int withdrawal );
	int		checkAmount( void ) const;
	void	displayStatus( void ) const;


private:

	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void ) {
        std::time_t t = std::time(nullptr);

        std::tm *tmb = std::localtime(&t);
        std::cout << std::put_time(tmb, "[%Y%m%d_%H%M%S] ");
    }

    int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

    int getAccountIndex() const { return (_accountIndex); }
    int getAmount() const { return (_amount); }
    int getNbDeposits() const { return (_nbDeposits); }
    int getNbWithdrawals() const { return (_nbWithdrawals); }
    Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
