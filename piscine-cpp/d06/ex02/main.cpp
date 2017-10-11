/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 17:33:04 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/11 17:54:50 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
  Base *base;

  int i = rand() % 3;
  if (i == 0) {
    base = new A();
  } else if (i == 1) {
    base = new B();
  } else {
    base = new C();
  }
  return base;
}

void identify_from_pointer(Base * p) {
  if (dynamic_cast<A*>(p) != NULL) {
    std::cout << "Type: A" << std::endl;
  } else if (dynamic_cast<B*>(p) != NULL) {
    std::cout << "Type: B" << std::endl;
  } else if (dynamic_cast<C*>(p) != NULL) {
    std::cout << "Type: C" << std::endl;
  } else {
    std::cout << "Unknown type" << std::endl;
  }
  return;
}

void identify_from_reference(Base & p) {
  if (dynamic_cast<A*>(&p) != NULL) {
    std::cout << "Type: A" << std::endl;
  } else if (dynamic_cast<B*>(&p) != NULL) {
    std::cout << "Type: B" << std::endl;
  } else if (dynamic_cast<C*>(&p) != NULL) {
    std::cout << "Type: C" << std::endl;
  } else {
    std::cout << "Unknown type" << std::endl;
  }
  return;
}

int main(void) {
  std::srand(std::time(NULL) + std::clock());
  Base * base = generate();

  identify_from_pointer(base);
  identify_from_reference(*base);
  
  return (0);
}