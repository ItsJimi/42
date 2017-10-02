/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 10:34:35 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/02 12:36:08 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Contact.class.hpp"

Contact::Contact() {
  // std::cout << "Constructor !" << std::endl;
}

Contact::~Contact() {
  // std::cout << "Destructor !" << std::endl;
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
    for(unsigned long i = 0; i < 10 - str.length(); i++) {
      str = " " + str;
    }
  }
  std::cout << str;
}

void Contact::display(int i) {
  std::cout << "|";
  print(std::to_string(i));
  std::cout << "|";
  print(this->firstname);
  std::cout << "|";
  print(this->lastname);
  std::cout << "|";
  print(this->nickname);
  std::cout << "|" << std::endl;
  return;
}