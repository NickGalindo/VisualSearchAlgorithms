#ifndef GRID_H
#define GRID_H

#include "tile.h"
#include <SFML/Graphics.hpp>
#include <queue>
#include <utility>

using namespace std;

class Grid {
public:
  Tile *arr;
  int sizex, sizey;

  Grid(int x, int y);
  void draw(sf::RenderWindow *window);
  void setOpen(int x, int y);
  void setBlocked(int x, int y);
  void setProcessing(int x, int y);
  void setStartTile(int x, int y);
  void setEndTile(int x, int y);
  void setPathTile(int x, int y);
  char getState(int x, int y);
};

#endif
