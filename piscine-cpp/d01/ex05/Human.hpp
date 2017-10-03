/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 12:46:45 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 13:53:49 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include "Brain.hpp"
#include <iostream>

class Human {
public:
  Human(void);
  ~Human(void);
  std::string identify(void) const;
  Brain const & getBrain(void) const;

private:
  Brain const _brain;
};

#endif