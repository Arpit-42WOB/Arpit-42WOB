/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:39:15 by amehrotr          #+#    #+#             */
/*   Updated: 2024/01/25 13:43:21 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts++;
	this->_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl; 
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
	_nbAccounts--;
	_totalAmount -= _amount;
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	if (_amount < withdrawal)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t now = time(0);
	tm *ltm = localtime(&now);

	std::cout << "[";
	std::cout << 1900 + ltm->tm_year;
	ltm->tm_mon < 10 ? std::cout << "0" << 1 + ltm->tm_mon : std::cout << 1 + ltm->tm_mon;
	ltm->tm_mday < 10 ? std::cout << "0" <<ltm->tm_mday : std::cout << ltm->tm_mday;
	std::cout << "_";
	ltm->tm_hour < 10 ? std::cout << "0" << ltm->tm_hour : std::cout << ltm->tm_hour;
	ltm->tm_min < 10 ? std::cout << "0" << ltm->tm_min : std::cout << ltm->tm_min;
	ltm->tm_sec < 10 ? std::cout << "0" << ltm->tm_sec : std::cout << ltm->tm_sec;
	std::cout << "]";
}

int Account::checkAmount(void) const
{
	return (_amount);
}