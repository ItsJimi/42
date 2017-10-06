/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 10:15:09 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/06 11:21:32 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>
#include <sstream>

class Victim {
public:
  Victim(Victim const & src);
  Victim(std::string name);
  ~Victim(void);

  Victim& operator=(Victim const & rhs);
  std::ostream & operator<<(std::ostream & stream, Victim const & rhs);

  std::string getName(void);
  void getPolymorphed(void);

private:
  Victim(void);

  std::string _name;
};

#endif