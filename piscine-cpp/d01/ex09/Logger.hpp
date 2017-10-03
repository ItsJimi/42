/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 18:12:05 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 18:48:05 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

#include <iostream>
#include <fstream>
#include <sstream>

class Logger {
public:
  Logger(std::string filename);
  void log(std::string const & dest, std::string const & message);

private:
  void logToConsole(std::string str);
  void logToFile(std::string str);
  std::string makeLogEntry(std::string str);
  std::string _filename;
};

#endif