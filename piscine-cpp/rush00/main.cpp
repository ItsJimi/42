/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 09:21:33 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/08 18:20:58 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "Game.class.hpp"

int main(void) {
  struct timespec timeOut, remains;
  timeOut.tv_sec = 0;
  timeOut.tv_nsec = 10000000;

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

  Game game = Game();
  game.init();

  while (1) {
    game.inputLogic();
    game.moveEntities();
    game.display();
    nanosleep(&timeOut, &remains);
  }
  getch();
  endwin();
  
  return (0);
}