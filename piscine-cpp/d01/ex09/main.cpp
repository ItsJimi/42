/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 18:11:30 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 18:44:21 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int main(void) {
  Logger logger = Logger("jimi.log");

  logger.log("console", "test test");
  logger.log("file", "bla bla");
  return (0);
}