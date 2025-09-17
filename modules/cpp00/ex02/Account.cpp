/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 12:18:58 by rhvidste          #+#    #+#             */
/*   Updated: 2025/09/17 14:06:14 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

/*---------------------------Static Member Variables--------------------------*/
/**
 * These exist outside of the object and within the class itself.
 */
int	Account::_nbAccounts = 0;
int	Account::_totalNbWithdrawals = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalAmount = 0;

/*--------------------------Private Member Functions--------------------------*/
void	Account::_displayTimestamp(void)
{
	time_t	now = time(0);
	struct	tm	*ltm = localtime(&now);

	std::cout << "[" << std::setfill('0') << std::setw(4) << ltm->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << ltm->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << ltm->tm_mday << "_";
	std::cout << std::setfill('0') << std::setw(2) << ltm->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << ltm->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << ltm->tm_sec << "] ";
}

/*--------------------------Constructors/Destructors--------------------------*/
Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_totalNbDeposits = 0;
	Account::_totalNbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
	_nbAccounts--;
	_totalAmount -= _amount;
}

/*-----------------------------------Getters----------------------------------*/
int	Account::getNbAccounts( void )
{
	return ( Account::_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return ( Account::_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return ( Account::_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return ( Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits() << ";withdrawals:" << ";withdrawas:" << getNbWithdrawals() << std::endl;
}
/*----------------------------Public Member Functions-------------------------*/
void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	std::cout << ";withdrawal:";
	if (_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int	Account::checkAmount( void ) const
{
	return ( Account::_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}
