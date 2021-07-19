#include "window_config.h"
#include "colors.h"
#include "runAlgorithm.h"
#include "BFS.h"

#include <iostream>

using namespace std;

int main() {
  sf::RenderWindow window(sf::VideoMode(WINDOW_GRID_WIDTH*11, WINDOW_GRID_HEIGHT*11), "SFML works!");

  runAlgorithm(&window, new BFS_struct(WINDOW_GRID_WIDTH, WINDOW_GRID_HEIGHT));

  //
  // Grid board(WINDOW_GRID_WIDTH, WINDOW_GRID_HEIGHT);
  //
  // while (window.isOpen()) {
  //   sf::Event event;
  //   while(window.pollEvent(event)) {
  //     if(event.type == sf::Event::Closed){
  //       window.close();
  //     }else if(event.type == sf::Event::MouseButtonPressed){
  //       int x = event.mouseButton.x / 11;
  //       int y = event.mouseButton.y / 11;
  //       if(event.mouseButton.button == sf::Mouse::Left){
  //         board.setBlocked(x, y);
  //       }else if(event.mouseButton.button == sf::Mouse::Right){
  //         board.setOpen(x, y);
  //       }
  //     }
  //   }
  //
  //   window.clear(BACKGROUND_COLOR);
  //   board.draw(&window);
  //   window.display();
  // }

  return 0;
}
