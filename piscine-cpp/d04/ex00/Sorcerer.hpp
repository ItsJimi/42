/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 10:14:49 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/06 11:21:42 by jmaiquez         ###   ########.fr       */
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
  std::ostream & operator<<(std::ostream & stream, Sorcerer const & rhs);

  std::string getName(void);
  std::string getTitle(void);

  void polymorph(Victim const & victim) const;

private:
  Sorcerer(void);

  std::string _name;
  std::string _title;
};

#endif