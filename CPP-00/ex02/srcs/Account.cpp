/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 21:06:50 by asmati            #+#    #+#             */
/*   Updated: 2026/01/30 00:04:12 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbDeposits++;
	_totalAmount += initial_deposit;
	
	_displayTimestamp();
	std::cout << "index" << _accountIndex << ";";
	std::cout << "amout" << _amount << ";";
	std::cout << "created" << std::endl;
}


int Account::getNbAccounts(void){
    return _nbAccounts;
}

int Account::getTotalAmount(void){
    return _totalAmount;
}

int Account::getNbDeposits(void){
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void){
    return _totalNbWithdrawals;
}    


void  Account::displayAccountsInfos(void){
	_displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "Total" << _totalAmount << ";";
	std::cout << "deposits: " << _totalNbDeposits << ";";
	std::cout << "withdrawals" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void){
	time_t now = time(0);
    tm *ltm = localtime(&now);
  	std::cout << "[" << 1900 + ltm->tm_year;
    std::cout << (ltm->tm_mon + 1 < 10 ? "0" : "") << 1 + ltm->tm_mon;
    std::cout << (ltm->tm_mday < 10 ? "0" : "") << ltm->tm_mday << "_";
    std::cout << (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour;
    std::cout << (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min;
    std::cout << (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec << "] ";

}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount" << _amount << ";";
	std::cout << "deposit" << deposit << ";";
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << "amount" << _amount << ";";
	std::cout << "nb_deposits: " << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amout" << _amount << ";";
	
	if(withdrawal > _amount){
		std::cout << "withdrawl refused:" << std::endl;
		return false;}
	
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= _amount;
	_totalNbWithdrawals++;
	
	std::cout << "amount" << _amount << ";";
	std::cout << "nb_withdrawls:" << _totalNbWithdrawals << std::endl;
	return true;
}

int Account::checkAmount(void) const{
		return _amount;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index" << _accountIndex << ";";
	std::cout << "amout" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals" << _nbWithdrawals << std::endl;
}

Account::~Account(void){
	;
}
