#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

class Tile {
public:
  char state;
  int posx, posy;
  sf::RectangleShape rect;

  Tile();
  Tile(int x, int y);
  Tile(int x, int y, char curState);

  void update(sf::RenderWindow *window);
  void setOpen();
  void setBlocked();
  void setProcessing();
  void setStartTile();
  void setEndTile();
  void setPathTile();
  void setPosition(int x, int y);
};

#endif
