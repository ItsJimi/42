/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 14:32:56 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/06 15:15:54 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

#include <iostream>
#include "Enemy.hpp"

class RadScorpion : public Enemy {
public:
  RadScorpion(void);
  RadScorpion(RadScorpion const & src);
  virtual ~RadScorpion(void);

  RadScorpion& operator=(RadScorpion const & rhs);

  using Enemy::takeDamage;
};

#endif