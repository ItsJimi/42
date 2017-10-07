/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 11:26:48 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/07 15:04:11 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILE_CLASS_HPP
# define MISSILE_CLASS_HPP

#include <iostream>
#include "GameEntity.class.hpp"

class Missile : public GameEntity {
public:
  Missile(std::string name, char type, int width, int height, int x, int y);
  Missile(Missile const & src);
  virtual ~Missile(void);

  Missile& operator=(Missile const & rhs);

private:
  Missile(void);
};

#endif