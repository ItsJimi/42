/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 11:31:35 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 11:36:05 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
  std::string str = "HI THIS IS BRAIN";

  std::string* strPtr = &str;
  std::string& strRef = str;

  std::cout << *strPtr << std::endl;
  std::cout << strRef << std::endl;

  return (0);
}