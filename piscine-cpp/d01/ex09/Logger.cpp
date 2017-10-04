/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 18:12:00 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/04 19:23:20 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

Logger::Logger(std::string filename) : _filename(filename) {
  return;
}

void Logger::log(std::string const & dest, std::string const & message) {
  std::string actionsTab[2] = {"console", "file"};

  typedef void (Logger::*Actions)(std::string str);
  Actions actions[2] = {&Logger::logToConsole, &Logger::logToFile};

  for (int i = 0; i < 2; i++) {
    if (actionsTab[i] == dest) {
      (this->*(actions[i]))(this->makeLogEntry(message));
      break;
    }
  }

  return;
}

void Logger::logToConsole(std::string str) {
  std::cout << str;
  return;
}

void Logger::logToFile(std::string str) {
  std::ofstream ofs(this->_filename, std::ios::app);
  if (ofs == 0) {
    std::cout << "Can't write file." << std::endl;
    return;
  }
  ofs << str;
  ofs.close();
  return;
}

std::string now( const char* format = "%c" ) {
  std::time_t t = std::time(0);
  char cstr[128];
  std::strftime(cstr, sizeof(cstr), format, std::localtime(&t));
  return cstr;
}

std::string Logger::makeLogEntry(std::string str) {
  std::stringstream date;
  date << "[" << now( "%D %H:%M:%S" ) << "] " << str << std::endl;
  return date.str();
}