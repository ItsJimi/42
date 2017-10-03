/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 09:44:23 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 10:50:10 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main(void) {
  ZombieEvent event = ZombieEvent();

  event.setZombieType("Hunter");
  Zombie* zombie1 = event.randomChump();

  event.setZombieType("Splitter");
  Zombie* zombie2 = event.randomChump();

  event.setZombieType("Witcher");
  Zombie* zombie3 = event.newZombie("Billy");
  zombie3->announce();

  delete zombie1;
  delete zombie2;
  delete zombie3;

  return(0);
}