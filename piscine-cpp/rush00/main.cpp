/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 09:21:33 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/08 11:59:02 by jmaiquez         ###   ########.fr       */
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
  start_color();
  init_color(COLOR_MAGENTA, 200, 200, 200);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_BLUE, COLOR_BLACK);
  init_pair(100, COLOR_MAGENTA, COLOR_BLACK);

  Game game = Game(1);
  game.init();
  game.createEntity("StarShip", 0, 0, 1, 1);


  while (1) {
    game.fetchAndCalc();
    game.moveEntities();
    game.display();
    usleep(1000);
  }
  getch();
  endwin();
  
  return (0);
}