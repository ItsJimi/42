/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 14:46:16 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/11 17:11:40 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void) {
  Array<int> numbers = Array<int>(2);

  std::cout << "numbers size: " << numbers.size() << std::endl;
  try {
    numbers[0] = 4;
    std::cout << "numbers 0: " << numbers[0] << std::endl;
  } catch (std::exception e) {
    std::cout << e.what() << std::endl;
  }
  try {
    numbers[1] = 2;
    std::cout << "numbers 1: " << numbers[1] << std::endl;
  } catch (std::exception e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "-------------------------------------------" << std::endl;

  Array<std::string> names = Array<std::string>(1);

  std::cout << "names size: " << names.size() << std::endl;
  try {
    names[0] = "Jimi";
    std::cout << "names 0: " << names[0] << std::endl;
  } catch (std::exception e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "-------------------------------------------" << std::endl;

  Array<char> letters = Array<char>();
  
  std::cout << "letters size: " << letters.size() << std::endl;
  try {
    letters[0] = 'A';
    std::cout << "letters 0: " << letters[0] << std::endl;
  } catch (std::exception e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << "-------------------------------------------" << std::endl;

  Array<int> numbersCopy = Array<int>(numbers);

  std::cout << "numbersCopy size: " << numbersCopy.size() << std::endl;

  return (0);
}