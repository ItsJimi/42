/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 10:14:49 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/06 12:55:11 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

#include <iostream>
#include <sstream>
#include "Victim.hpp"

class Sorcerer {
public:
  Sorcerer(Sorcerer const & src);
  Sorcerer(std::string name, std::string _title);
  ~Sorcerer(void);

  Sorcerer& operator=(Sorcerer const & rhs);

  std::string getName(void) const;
  std::string getTitle(void) const;

  void polymorph(Victim const & victim) const;

private:
  Sorcerer(void);

  std::string _name;
  std::string _title;
};

std::ostream & operator<<(std::ostream & stream, Sorcerer const & rhs);

#endif