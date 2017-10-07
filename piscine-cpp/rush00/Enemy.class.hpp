/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 11:23:18 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/07 15:04:42 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_HPP
# define ENEMY_CLASS_HPP

#include <iostream>
#include "GameEntity.class.hpp"

class Enemy : public GameEntity {
public:
  Enemy(std::string name, char type, int width, int height, int x, int y);
  Enemy(Enemy const & src);
  virtual ~Enemy(void);

  Enemy& operator=(Enemy const & rhs);

private:
  Enemy(void);
};

#endif