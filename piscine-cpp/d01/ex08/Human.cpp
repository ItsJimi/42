/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 16:45:11 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/03 18:08:25 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

void Human::meleeAttack(std::string const & target) {
  std::cout << "This is a melee attack to " << target << std::endl;
  return;
}
void Human::rangedAttack(std::string const & target) {
  std::cout << "This is a ranged attack to " << target << std::endl;
  return;
}

void Human::intimidatingShout(std::string const & target) {
  std::cout << "This is an intimidating shout to " << target << std::endl;
  return;
}

void Human::action(std::string const & action_name, std::string const & target) {
  std::string actionsTab[3] = {"meleeAttack", "rangedAttack", "intimidatingShout"};

  typedef void (Human::*Actions)(std::string const & target);
  Actions actions[3] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};

  for (int i = 0; i < 3; i++) {
    if (actionsTab[i] == action_name) {
      (this->*(actions[i]))(target);
      break;
    }
  }

  return;
}