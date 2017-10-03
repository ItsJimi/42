/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 12:43:24 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 13:45:12 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"

int main(void) {
  Human bob;

  std::cout << bob.identify() << std::endl;
  std::cout << bob.getBrain().identify() << std::endl;
  return (0);
}