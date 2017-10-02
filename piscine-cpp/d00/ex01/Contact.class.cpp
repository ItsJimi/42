/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 10:34:35 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/02 18:29:34 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"

Contact::Contact() {
  return;
}

Contact::~Contact() {
  return;
}

void Contact::add(void) {
  std::cout << "First name: ";
  std::getline(std::cin, this->_firstname);
  std::cout << "Last name: ";
  std::getline(std::cin, this->_lastname);
  std::cout << "Nickname: ";
  std::getline(std::cin, this->_nickname);
  std::cout << "Login: ";
  std::getline(std::cin, this->_login);
  std::cout << "Postal address: ";
  std::getline(std::cin, this->_postalAddress);
  std::cout << "Email address: ";
  std::getline(std::cin, this->_emailAddress);
  std::cout << "Phone number: ";
  std::getline(std::cin, this->_phoneNumber);
  std::cout << "Birthday date: ";
  std::getline(std::cin, this->_birthdayDate);
  std::cout << "Favorite meal: ";
  std::getline(std::cin, this->_favoriteMeal);
  std::cout << "Underwear color: ";
  std::getline(std::cin, this->_underwearColor);
  std::cout << "Darkest secret: ";
  std::getline(std::cin, this->_darkestSecret);

  std::cout << std::endl << this->_firstname << " " << this->_lastname << " has been added." << std::endl;
  return;
}

void Contact::_print(std::string str) {
  if (str.length() > 10) {
    str = str.substr(0, 9) + ".";
  } else if (str.length() < 10) {
    str = std::string("          ").substr(0, 10 - str.length()) + str;
  }
  std::cout << str;
}

void Contact::display(void) {
  std::cout << "|";
  this->_print(this->_firstname);
  std::cout << "|";
  this->_print(this->_lastname);
  std::cout << "|";
  this->_print(this->_nickname);
  std::cout << "|" << std::endl;
  return;
}

void Contact::displayAll(void) {
  std::cout << "First name: " << this->_firstname << std::endl;
  std::cout << "Last name: " << this->_lastname << std::endl;
  std::cout << "Nickname: " << this->_nickname << std::endl;
  std::cout << "Login: " << this->_login << std::endl;
  std::cout << "Postal address: " << this->_postalAddress << std::endl;
  std::cout << "Email address: " << this->_emailAddress << std::endl;
  std::cout << "Phone number: " << this->_phoneNumber << std::endl;
  std::cout << "Birthday date: " << this->_birthdayDate << std::endl;
  std::cout << "Favorite meal: " << this->_favoriteMeal << std::endl;
  std::cout << "Underwear color: " << this->_underwearColor << std::endl;
  std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
  return;
}