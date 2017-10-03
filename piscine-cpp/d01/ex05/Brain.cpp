/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 12:45:19 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 13:53:01 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
  std::cout << "Brain created" << std::endl;
  return;
}

Brain::~Brain(void) {
  return;
}

std::string Brain::identify(void) const {
  std::stringstream stream;
  stream << this;

  return (stream.str());
}