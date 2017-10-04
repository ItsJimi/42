/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 09:44:44 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/04 18:10:25 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include <iostream>
#include "Zombie.hpp"

class ZombieHorde {
  public:
    ZombieHorde(int N);
    ~ZombieHorde(void);
    void announce(void) const;

  private:
    std::string _getRandomName(void);
    Zombie* _zombies;
    int _nbrZombies;
};

#endif