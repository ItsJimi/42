/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 08:54:05 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/05 11:08:45 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  {
    FragTrap robot = FragTrap("Bobot");
    
    robot.rangedAttack("Zeeee");
    robot.meleeAttack("Zeeee");
    robot.takeDamage(105);
    robot.vaulthunter_dot_exe("Zeeee");
    robot.beRepaired(25);
    robot.vaulthunter_dot_exe("Zeeee");
  }
  std::cout << std::endl;
  {
    ScavTrap robot = ScavTrap("Bobot");
    
    robot.rangedAttack("Zeeee");
    robot.meleeAttack("Zeeee");
    robot.takeDamage(105);
    robot.challengeNewcomer();
    robot.beRepaired(25);
    robot.challengeNewcomer();
  }
  return 0;
}