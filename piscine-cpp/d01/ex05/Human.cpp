/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 12:48:28 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 13:53:53 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void) : _brain(Brain()) {
  std::cout << "Human created" << std::endl;
  return;
}

Human::~Human(void) {
  return;
}

Brain const & Human::getBrain(void) const {
  return (this->_brain);
}

std::string Human::identify(void) const {
  return (this->_brain.identify());
}