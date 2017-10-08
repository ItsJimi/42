/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaiquez <jmaiquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 14:16:31 by jmaiquez          #+#    #+#             */
/*   Updated: 2017/10/08 20:52:23 by jmaiquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"

/* OPERATORS */

Game::Game(void) : _choice(-1), _score(0), isRunning(true) {
  std::srand(std::time(NULL) + std::clock());
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

  this->_cols = COLS;
  this->_lines = LINES;
  return;
}

Game::Game(Game const & src) {
  *this = src;
  return;
}

Game::~Game(void) {
  clear();
  nodelay(stdscr, FALSE);
  mvprintw(this->_lines / 2, this->_cols / 2, ("Score: " + std::to_string(this->_score)).c_str());
  refresh();
  getch();
  endwin();
  return;
}

/* MEMBERS */

void  Game::init(void) {
  // Initialize grid map
  this->_points = new Point*[this->_lines];
  for (int i = 0; i < this->_lines; i++) {    
    this->_points[i] = new Point[this->_cols];
  }

  // Initialize background
  for (int i = 0; i < this->_lines; i++) {
    for (int j = 0; j < this->_cols; j++) {
      if (rand() % 20 == 0)
				this->_points[i][j].back = true;
			else
				this->_points[i][j].back = false;
    }
  }

  // Create player
  this->_createEntity("StarShip", 0, 0, 3, 1);
  return;
}

void  Game::_createEntity(std::string entity, int x, int y, int w, int h) {
  // Check if entity exist
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (this->_points[y + i][x + j].entity)
        return;
    }
  }

  // Create right entity
  GameEntity *tmp;

  if (entity == "StarShip") {
    tmp = new StarShip("Luke", 'o', w, h, (int)(this->_cols / 2 - w),  (int)(this->_lines - 2));
    this->_player = tmp;
  } else if (entity == "Enemy") {
    tmp = new Enemy("Dark Vador", 'W', w, h, x, y);
  } else if (entity == "DarkMissile") {
    tmp = new Enemy("Dark Missle", 'w', w, h, x, y);
  } else if (entity == "Missile") {
    tmp = new Missile("Missile", '|', w, h, x, y);
  } else {
    return;
  }

  // Put entity to map
  for (int i = 0; i < tmp->getHeight(); i++) {
    for (int j = 0; j < tmp->getWidth(); j++) {
      this->_points[tmp->getY() + i][tmp->getX() + j].entity = tmp;
      this->_points[i][j].isMoved = false;
    }
  }
  return;
}

void Game::display(void) {
  // Draw entity or background on screen
  for (int i = 0; i < this->_lines; i++) {
    for (int j = 0; j < this->_cols; j++) {
      if (this->_points[i][j].entity) {
        if (this->_points[i][j].entity->getType() == 'o') {
          attron(COLOR_PAIR(1));
          mvaddch(i, j, this->_points[i][j].entity->getType());
          attroff(COLOR_PAIR(1));
        } else {
          mvaddch(i, j, this->_points[i][j].entity->getType());
        }
      } else {
        if (this->_points[i][j].back) {
          attron(COLOR_PAIR(100));
          mvaddch(i, j, '|');
          attroff(COLOR_PAIR(100));
        }
        else
          mvaddch(i, j, ' ');
      }
    }
  }

  // Draw score on screen
  mvprintw(0, 0, ("Score: " + std::to_string(this->_score)).c_str());
  refresh();
  return;
}

void Game::inputLogic(void) {
  // Frame counter
  this->_cmp += 1;
  
  // Get user inputs
  this->_choice = wgetch(stdscr);

  // Launch Missile when spacebar is pressed
  if (this->_choice == 32 && (this->_player->getY() != 0))
    this->_createEntity("Missile", this->_player->getX() + (this->_player->getWidth() / 2), this->_player->getY() - 1, 1, 1);
  
  // Exit game
  if (this->_choice == 'x')
    this->isRunning = false;
  return;
}

void  Game::_moveOneEntity(GameEntity *entity, int move) {
  /*
    1 = TOP
    2 = RIGHT
    3 = BOTTOM
    4 = LEFT
  */

  // User can't leave map
  if (move == 1 && entity->getY() == 0 && entity->getType() == 'o') return;
  if (move == 2 && entity->getX() + entity->getWidth() == this->_cols && entity->getType() == 'o') return;
  if (move == 3 && entity->getY() + entity->getHeight() == this->_lines && entity->getType() == 'o') return;
  if (move == 4 && entity->getX() == 0 && entity->getType() == 'o') return;

  // Delete Enemy and DarkMissile
  if (move == 3 && entity->getY() + entity->getHeight() == this->_lines  && entity->getType() != 'o') {
    int h = entity->getHeight();
    int w = entity->getWidth();
    int x = entity->getX();
    int y = entity->getY();
    delete entity;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        this->_points[i + y][j + x].entity = NULL;
      }
    }
    return;
  }

  // Delete Missile
  if (move == 1 && (entity->getY() == 0) && (entity->getType() != 'o')) {
    int h = entity->getHeight();
    int w = entity->getWidth();
    int x = entity->getX();
    int y = entity->getY();
    delete entity;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        this->_points[i + y][j + x].entity = NULL;
      }
    }
    return;
  }

  // Delete old points on map
  for (int i = 0; i < entity->getHeight(); i++) {
    for (int j = 0; j < entity->getWidth(); j++) {
      this->_points[entity->getY() + i][entity->getX() + j].entity = NULL;
    }
  }

  // Move entity
  switch (move) {
    case 1:
      entity->moveTop();
      break;
    case 2:
      entity->moveRight();
      break;
    case 3:
      entity->moveBottom();
      break;
    case 4:
      entity->moveLeft();
      break;
  }

  // Put entity on grid
  for (int i = 0; i < entity->getHeight(); i++) {
    for (int j = 0; j < entity->getWidth(); j++) {
      // if collision entity attack other entity
      if (this->_points[entity->getY() + i][entity->getX() + j].entity) {
        int attackScore = entity->attack(this->_points[entity->getY() + i][entity->getX() + j].entity, this->_points);
        if (attackScore == -1) {
          this->isRunning = false;
          return;
        }
        this->_score += attackScore;
        return;
      }
      // Put entity
      this->_points[entity->getY() + i][entity->getX() + j].entity = entity;
      this->_points[entity->getY() + i][entity->getX() + j].isMoved = true;
    }
  }
  return;
}

void Game::_popEnemy(void) {
  // Pop enemy randomly
	if (rand() % 25 == 0) {
    int w = (rand() % 5) + 1;
		int i = rand() % (this->_cols - w - 2);
		if (this->_points[0][i].entity == NULL)
      this->_createEntity("Enemy", i, 0, w, (rand() % 5) + 1);
	}
}

void Game::moveEntities(void) {
  // Call popEnemy
  this->_popEnemy();

  // Move background
  if(this->_cmp % 2 == 0)
    this->_decaleBack();

  // Move all entities
  for (int i = 0; i < this->_lines; i++) {
    for (int j = 0; j < this->_cols; j++) {
      // Entity already moved
      if(this->_points[i][j].isMoved)
        continue;

      // Move entity
      if (this->_points[i][j].entity) {
        // Move Enemy
        if (this->_points[i][j].entity->getType() == 'W' && this->_cmp % 8 == 0) {
          if (rand() % 10 == 0 && this->_points[i][j].entity->getY() + this->_points[i][j].entity->getHeight() < this->_lines - 3)
            this->_createEntity("DarkMissile", this->_points[i][j].entity->getX() + (this->_points[i][j].entity->getWidth() / 2), this->_points[i][j].entity->getY() + this->_points[i][j].entity->getHeight() + 2, 1, 1);
          this->_moveOneEntity(this->_points[i][j].entity, 3);
        }
        // Move Enemy Missile
        else if (this->_points[i][j].entity->getType() == 'w' && this->_cmp % 3 == 0)
          this->_moveOneEntity(this->_points[i][j].entity, 3);
        // Move player Missile
        else if (this->_points[i][j].entity->getType() == '|' && this->_cmp % 3 == 0)
          this->_moveOneEntity(this->_points[i][j].entity, 1);
        // Move player
        else if (this->_points[i][j].entity->getType() == 'o') {
          switch (this->_choice) {
          case 65: // TOP
            this->_moveOneEntity(this->_points[i][j].entity, 1);
            break;
          case 66: // BOTTOM
            this->_moveOneEntity(this->_points[i][j].entity, 3);
            break;
          case 68: // LEFT
            this->_moveOneEntity(this->_points[i][j].entity, 4);
            break;
          case 67: // RIGHT
            this->_moveOneEntity(this->_points[i][j].entity, 2);
            break;
          }
        }
      }
    }
  }

  // Reset isMoved
  for (int i = 0; i < this->_lines; i++) {
    for (int j = 0; j < this->_cols; j++) {
      this->_points[i][j].isMoved = false;
    }
  }

  // Reset choice
  this->_choice = -1;
}

void Game::_decaleBack(void) {
  // Move background
  for (int i = this->_lines - 2; i >= 0; i--) {
    for (int j = 0; j < this->_cols; j++) {
      if (this->_points[i][j].back) {
        this->_points[i][j].back = false;
        this->_points[i + 1][j].back = true;
      }
      else
        this->_points[i + 1][j].back = false;
    }
  }

  // Random first line
  for (int i = 0; i < this->_cols; i++) {
    if (rand() % 20 == 0)
			this->_points[0][i].back = true;
		else
			this->_points[0][i].back = false;
  }
	return;
}

/* OPERATORS */

Game &Game::operator=(Game const &rhs) {
  return *this;
}