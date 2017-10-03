/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 09:44:44 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 11:13:37 by jmaiquez         ###   ########.fr       */
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

  private:
    std::string _getRandomName(void);
    Zombie* _zombies;
};

#endif