/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 09:21:33 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/07 17:08:35 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "Game.class.hpp"

int main(void) {
  initscr();
  curs_set(0);
  nodelay(stdscr, TRUE);

  Game game = Game(1);
  game.init();
  game.createPlayer();
  while (1){
    game.fetchAndCalc();
    game.display();
    // usleep(500);
  }
  getch();
  endwin();
  
  return (0);
}