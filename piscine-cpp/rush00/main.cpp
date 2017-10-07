/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 09:21:33 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/07 19:39:34 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <unistd.h>
#include "Game.class.hpp"

int main(void) {
  initscr();
  curs_set(0);
  nodelay(stdscr, TRUE);
  noecho();

  Game game = Game(1);
  game.init();
  game.createEntity("StarShip", 0, 0);
  game.createEntity("Enemy", 10, 10);
  while (1){
    game.fetchAndCalc();
    game.moveEntities();
    game.display();
    usleep(1000);
  }
  getch();
  endwin();
  
  return (0);
}