/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 08:54:05 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/05 14:33:16 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main(void) {
  FragTrap robot1 = FragTrap("Alex");
  
  robot1.rangedAttack("Zeeee");
  robot1.meleeAttack("Zeeee");
  robot1.takeDamage(105);
  robot1.vaulthunter_dot_exe("Zeeee");
  robot1.beRepaired(25);
  robot1.vaulthunter_dot_exe("Zeeee");

  std::cout << std::endl;

  ScavTrap robot2 = ScavTrap("Florian");
    
  robot2.rangedAttack("Zeeee");
  robot2.meleeAttack("Zeeee");
  robot2.takeDamage(105);
  robot2.challengeNewcomer();
  robot2.beRepaired(25);
  robot2.challengeNewcomer();

  std::cout << std::endl;

  NinjaTrap robot3 = NinjaTrap("Jimi");
  NinjaTrap robot4 = NinjaTrap("Alexandre");
  
  robot3.rangedAttack("Zeeee");
  robot3.meleeAttack("Zeeee");
  robot3.takeDamage(105);
  robot3.ninjaShoebox(robot1);
  robot3.beRepaired(25);
  robot3.ninjaShoebox(robot1);
  robot3.ninjaShoebox(robot2);
  robot3.ninjaShoebox(robot4);

  std::cout << std::endl;
  
  SuperTrap robot5 = SuperTrap("God");
  
  robot5.rangedAttack("Zeeee");
  robot5.meleeAttack("Zeeee");
  robot5.takeDamage(105);
  robot5.ninjaShoebox(robot1);
  robot5.beRepaired(25);
  robot5.ninjaShoebox(robot1);
  robot5.ninjaShoebox(robot2);
  robot5.ninjaShoebox(robot4);
  
  return 0;
}