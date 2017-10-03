/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 16:44:22 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 18:08:24 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <map>
#include <iostream>

class Human {
private:
  void meleeAttack(std::string const & target);
  void rangedAttack(std::string const & target);
  void intimidatingShout(std::string const & target);
public:
  void action(std::string const & action_name, std::string const & target);
};

#endif