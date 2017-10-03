/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 16:39:24 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 18:08:27 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main(void) {
  Human human = Human();

  human.action("meleeAttack", "Zombie");
  human.action("rangedAttack", "Zombie");
  human.action("intimidatingShout", "Zombie");
  human.action("test", "Zombie");

  return (0);
}