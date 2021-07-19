#include "runAlgorithm.h"
#include "path_algorithm.h"
#include "grid.h"
#include "window_config.h"
#include "colors.h"

#include <SFML/Graphics.hpp>
#include <queue>
#include <utility>
#include <unordered_map>

#include <iostream>

#define ff first
#define ss second

using namespace std;

// Run the BFS subroutine
void runAlgorithm(sf::RenderWindow *window, PathAlgorithm *alg){
  // the board to render algorithm upon
  Grid board(WINDOW_GRID_WIDTH, WINDOW_GRID_HEIGHT);

  // game loop
  while(window->isOpen()){
    // manage the events
    sf::Event event;
    while(window->pollEvent(event)){
      // If the event is closed then close the window
      if(event.type == sf::Event::Closed){
        window->close();
        return;
      }

      // if the mouse is pressed then do some stuff
      if(event.type == sf::Event::MouseButtonPressed){
        int x = event.mouseButton.x / 11;
        int y = event.mouseButton.y / 11;

        // if the left mouse button was pressed then make a cell blocked
        if(event.mouseButton.button == sf::Mouse::Left){
          board.setBlocked(x, y);
          alg->check_point_edited(x, y);
          continue;
        }

        // if the right mouse button was pressed then remove the blocked cell
        if(event.mouseButton.button == sf::Mouse::Right){
          board.setOpen(x, y);
          alg->check_point_edited(x, y);
          continue;
        }
      }

      // if a key is pressed then do some stuff
      if(event.type == sf::Event::KeyPressed){
        // if escape was pressed then go back to previous page
        if(event.key.code == sf::Keyboard::Escape) return;

        // if ctrl+a then set a start point
        if(event.key.code == sf::Keyboard::A && event.key.control){
          int x = sf::Mouse::getPosition(*window).x / 11;
          int y = sf::Mouse::getPosition(*window).y / 11;
          board.setStartTile(x, y);
          alg->upd_start_point(x, y);
          continue;
        }

        // if ctrl+b then set the end point
        if(event.key.code == sf::Keyboard::B && event.key.control){
          int x = sf::Mouse::getPosition(*window).x / 11;
          int y = sf::Mouse::getPosition(*window).y / 11;
          board.setEndTile(x, y);
          alg->upd_end_point(x, y);
          continue;
        }

        // if ctrl+s then start the bfs
        if(event.key.code == sf::Keyboard::S && event.key.control){
          alg->start();
          continue;
        }

        // if ctrl+p then pause the bfs
        if(event.key.code == sf::Keyboard::P && event.key.control){
          alg->pause();
          continue;
        }
      }
    }

    if(alg->running()){
      alg->run(&board);
    }

    window->clear(BACKGROUND_COLOR);
    board.draw(window);
    window->display();
  }

  return;
}
