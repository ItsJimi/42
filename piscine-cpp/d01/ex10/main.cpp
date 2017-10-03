/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 19:06:11 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 19:33:28 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
  if (argc == 1) {
    std::string str;
    while (1) {
      std::cin >> str;
      std::cout << str << std::endl;
    }
  }

  for (int i = 1; i < argc; i++) {
    std::ifstream ifs(argv[i]);

    if (ifs == 0) {
      std::cout << argv[0] << ": " << argv[i] << ": No such file or directory" << std::endl;
      return (1);
    }

    char c;
    while(!ifs.eof()) {
      ifs >> std::noskipws >> c;
      std::cout << c;
    }
    std::cout << std::endl;
  }
  return (0);
}