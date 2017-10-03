/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 09:44:44 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 10:40:02 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include <iostream>
#include "Zombie.hpp"

class ZombieEvent {
  public:
    ZombieEvent(void);
    ~ZombieEvent(void);
    void setZombieType(std::string type);
    Zombie* newZombie(std::string name) const;
    Zombie* randomChump() const;
  
  private:
    std::string _type;
};

#endif