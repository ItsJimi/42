/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 15:58:34 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/02 16:59:32 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.class.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(0), _nbDeposits(initial_deposit), _nbWithdrawals(0) {
  Account::_displayTimestamp();
  std::cout << "index:" << _nbAccounts << ";amount:" << initial_deposit << ";created" << std::endl;
  Account::_nbAccounts++;
  return;
}

Account::~Account(void) {
  Account::_nbAccounts--;
  return;
}

int	Account::getNbAccounts(void) {
  return Account::_nbAccounts;
}

int Account::getTotalAmount(void) {
  return Account::_totalAmount;
}

int	Account::getNbDeposits(void) {
  return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void) {
  return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
  Account::_displayTimestamp();
  std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
  return;
}

// [20150406_153629] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1

void Account::makeDeposit(int deposit) {
  this->_amount += deposit;
  this->_nbDeposits++;
  Account::_totalNbDeposits++;
  Account::_totalAmount += deposit;
  return;
}

bool Account::makeWithdrawal(int withdrawal) {
  Account::_displayTimestamp();

  if (withdrawal > this->_amount) {
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawals:refused" << std::endl;
    return false;
  }

  std::string p_amount = this->_amount;
  this->_amount -= withdrawal;
  this->_nbWithdrawals++;
  Account::_totalNbWithdrawals++;
  std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount << ";withdrawals:" << withdrawal << std::endl;
  return true;
}

int Account::checkAmount(void) const {
  return this->_amount;
}

void Account::displayStatus(void) const {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
  return;
}

void	_displayTimestamp(void) {
  std::cout << "[] ";
  return;
}