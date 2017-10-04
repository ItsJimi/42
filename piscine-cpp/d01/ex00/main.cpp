/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 09:12:48 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/04 17:39:56 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void ponyOnTheStack(void) {
  Pony littlePony = Pony("blue");
  littlePony.jump();
  return;
}

void ponyOnTheHeap(void) {
  Pony* bigPony = new Pony("purple");
  delete bigPony;
  return;
}

int main(void) {
  ponyOnTheHeap();
  ponyOnTheStack();
  std::cout << "No pony" << std::endl;
  return (0);
}