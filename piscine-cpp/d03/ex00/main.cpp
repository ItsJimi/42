/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 08:54:05 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/05 10:48:42 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void) {
  FragTrap robot = FragTrap("Bobot");
  
  robot.rangedAttack("Zeeee");
  robot.meleeAttack("Zeeee");
  robot.takeDamage(105);
  robot.vaulthunter_dot_exe("Zeeee");
  robot.beRepaired(25);
  robot.vaulthunter_dot_exe("Zeeee");

  return 0;
}