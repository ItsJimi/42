/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 10:26:06 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/02 12:22:21 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Contact.class.hpp"

int main() {
  std::string buf;
  Contact contacts[8];
  int n = 0;

  while (1) {
    std::cout << "> ";
    std::getline(std::cin, buf);

    if (buf == "EXIT") {
      return (0);
    } else if (buf == "ADD") {
      if (n == 8) {
        std::cout << "Your phonebook is full, please buy an other.";
        return(0);
      }
      contacts[n].add();
      n++;
    } else if (buf == "SEARCH") {
      for (int i = 0; i < n; i++) {
        contacts[i].display(i);
      }
    }
  }
}