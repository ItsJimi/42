/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 15:58:34 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/02 17:47:40 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.class.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
  Account::_nbAccounts++;
  Account::_totalAmount += this->_amount;
  return;
}

Account::~Account(void) {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
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

void Account::makeDeposit(int deposit) {
  int p_amount = this->_amount;
  this->_amount += deposit;
  this->_nbDeposits++;
  Account::_totalNbDeposits++;
  Account::_totalAmount += deposit;
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
  return;
}

bool Account::makeWithdrawal(int withdrawal) {
  Account::_displayTimestamp();

  if (withdrawal > this->_amount) {
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
    return false;
  }

  int p_amount = this->_amount;
  this->_amount -= withdrawal;
  this->_nbWithdrawals++;
  Account::_totalNbWithdrawals++;
  Account::_totalAmount -= withdrawal;
  std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
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

void	Account::_displayTimestamp(void) {
  std::cout << "[20150406_153629] ";
  return;
}