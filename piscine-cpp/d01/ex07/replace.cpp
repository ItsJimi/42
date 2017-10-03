/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:44:41 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 16:40:17 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
  if (argc != 4 || std::string(argv[1]) == "" || std::string(argv[2]) == "" || std::string(argv[3]) == "") {
    std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
    return (1);
  }

  std::ifstream ifs(argv[1]);
  if (ifs == 0) {
    std::cout << argv[1] << " doesn't exist." << std::endl;
    return (1);
  }

  std::string text = "";
  char c;
  while (ifs >> std::noskipws >> c) {
    text += c;
  }

  size_t index = 0;
  while (true) {
    index = text.find(argv[2], index);
    if (index == std::string::npos) break;

    text.replace(index, std::string(argv[2]).length(), argv[3]);

    index += std::string(argv[3]).length();
  }

  std::ofstream ofs(std::string(argv[1]) + ".replace");
  if (ofs == 0) {
    std::cout << "Can't write " << argv[1] << ".replace" << std::endl;
    return (1);
  }
  ofs << text;

  return (0);
}