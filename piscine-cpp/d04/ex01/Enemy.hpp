/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 14:02:59 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/06 15:23:05 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>

class Enemy {
public:
  Enemy(Enemy const & src);
  Enemy(int hp, std::string const & type);
  virtual ~Enemy(void);

  Enemy& operator=(Enemy const & rhs);

  std::string getType(void) const;
  int getHP(void) const;
  virtual void takeDamage(int damages);

private:
  Enemy(void);

protected:
  int _hitPoints;
  std::string _type;
};

#endif