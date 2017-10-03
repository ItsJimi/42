/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 09:32:25 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 09:40:20 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void memoryLeak() {
  std::string* panthere = new std::string("String panthere");
  std::cout << *panthere << std::endl;
  delete panthere;
}

int main(void) {
  memoryLeak();
  return(0);
}