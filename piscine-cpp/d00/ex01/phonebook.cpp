/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 10:26:06 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/02 14:25:15 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"

int main() {
  std::string buf;
  Contact contacts[8];
  int n = 0;

  while (1) {
    std::cout << "Available commands (ADD, SEARCH, EXIT)" << std::endl;
    std::cout << "> ";
    std::getline(std::cin, buf);

    if (buf == "EXIT") {
      return (0);
    } else if (buf == "ADD") {
      if (n == 8) {
        std::cout << "Your phonebook is full, please buy an other." << std::endl;
        return(0);
      }
      contacts[n].add();
      n++;
    } else if (buf == "SEARCH") {
      if (n > 0) {
        std::cout << "|     Index| Firstname|  Lastname|  Nickname|" << std::endl;
        std::cout << "|----------|----------|----------|----------|" << std::endl;
        for (int i = 0; i < n; i++) {
          std::cout << "|         " << i + 1;
          contacts[i].display();
        }

        std::cout << "Index of research: ";
        std::getline(std::cin, buf);
        int index = std::atoi(buf.c_str());
        if (index - 1 <= n && index - 1 >= 0) {
          contacts[index - 1].displayAll();
        } else {
          std::cout << "404 not found" << std::endl;
        }
      } else {
        std::cout << "Your phonebook is empty." << std::endl;
      }
    }
  }
}