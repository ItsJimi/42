/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:02:10 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/11 14:44:04 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void iter(T * tab, size_t length, void (*f)(T)) {
  for (int i = 0; i < length; i++) {
    f(tab[i]);
  }
  return;
}

void print(std::string str) {
  std::cout << str << std::endl;
}

int main(void) {
  std::string names[] = {"Jimi", "Alex", "Florian", "Alexandre", "Valentin", "David"};
  
  ::iter(names, 6, print);
  return (0);
}