/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 10:34:35 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/02 14:19:39 by jmaiquez         ###   ########.fr       */
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
  std::getline(std::cin, this->firstname);
  std::cout << "Last name: ";
  std::getline(std::cin, this->lastname);
  std::cout << "Nickname: ";
  std::getline(std::cin, this->nickname);
  std::cout << "Login: ";
  std::getline(std::cin, this->login);
  std::cout << "Postal address: ";
  std::getline(std::cin, this->postalAddress);
  std::cout << "Email address: ";
  std::getline(std::cin, this->emailAddress);
  std::cout << "Phone number: ";
  std::getline(std::cin, this->phoneNumber);
  std::cout << "Birthday date: ";
  std::getline(std::cin, this->birthdayDate);
  std::cout << "Favorite meal: ";
  std::getline(std::cin, this->favoriteMeal);
  std::cout << "Underwear color: ";
  std::getline(std::cin, this->underwearColor);
  std::cout << "Darkest secret: ";
  std::getline(std::cin, this->darkestSecret);

  std::cout << std::endl << this->firstname << " " << this->lastname << " has been added." << std::endl;
  return;
}

void Contact::print(std::string str) {
  if (str.length() > 10) {
    str = str.substr(0, 9) + ".";
  } else if (str.length() < 10) {
    str = std::string("          ").substr(0, 10 - str.length()) + str;
  }
  std::cout << str;
}

void Contact::display(void) {
  std::cout << "|";
  print(this->firstname);
  std::cout << "|";
  print(this->lastname);
  std::cout << "|";
  print(this->nickname);
  std::cout << "|" << std::endl;
  return;
}

void Contact::displayAll(void) {
  std::cout << "First name: " << this->firstname << std::endl;
  std::cout << "Last name: " << this->lastname << std::endl;
  std::cout << "Nickname: " << this->nickname << std::endl;
  std::cout << "Login: " << this->login << std::endl;
  std::cout << "Postal address: " << this->postalAddress << std::endl;
  std::cout << "Email address: " << this->emailAddress << std::endl;
  std::cout << "Phone number: " << this->phoneNumber << std::endl;
  std::cout << "Birthday date: " << this->birthdayDate << std::endl;
  std::cout << "Favorite meal: " << this->favoriteMeal << std::endl;
  std::cout << "Underwear color: " << this->underwearColor << std::endl;
  std::cout << "Darkest secret: " << this->darkestSecret << std::endl;
  return;
}