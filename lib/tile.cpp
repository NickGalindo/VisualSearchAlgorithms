#include "tile.h"
#include "colors.h"
#include <SFML/Graphics.hpp>

//Set of different constructors

Tile::Tile(int x, int y, char curState){
  posx = x;
  posy = y;
  state = curState;

  rect.setSize(sf::Vector2f(10, 10));
  rect.setPosition(posx, posy);

  // 'a' for open, 'b' for blocked, 'c' for under processing, 's' for start tile, 'e' for end tile
  if(state == 'a'){
    rect.setFillColor(OPEN_COLOR);
    return;
  }
  if(state == 'b'){
    rect.setFillColor(BLOCKED_COLOR);
    return;
  }
  if(state == 'c'){
    rect.setFillColor(PROCESSING_COLOR);
    return;
  }
  if(state == 's'){
    rect.setFillColor(START_TILE_COLOR);
    return;
  }
  if(state == 'e'){
    rect.setFillColor(END_TILE_COLOR);
    return;
  }
  if(state == 'p'){
    rect.setFillColor(PATH_COLOR);
    return;
  }
  return;
}

Tile::Tile(int x, int y){
  posx = x;
  posy = y;
  state = 'a';

  rect.setSize(sf::Vector2f(10, 10));
  rect.setPosition(posx, posy);

  rect.setFillColor(OPEN_COLOR);
  return;
}

Tile::Tile(){
  posx = 0;
  posy = 0;
  state = 'a';

  rect.setSize(sf::Vector2f(10, 10));
  rect.setPosition(posx, posy);

  rect.setFillColor(OPEN_COLOR);
  return;
}


// Class functions
void Tile::setOpen(){
  state = 'a';
  rect.setFillColor(OPEN_COLOR);
  return;
}
void Tile::setBlocked(){
  state = 'b';
  rect.setFillColor(BLOCKED_COLOR);
  return;
}
void Tile::setProcessing(){
  state = 'c';
  rect.setFillColor(PROCESSING_COLOR);
  return;
}
void Tile::setStartTile(){
  state = 's';
  rect.setFillColor(START_TILE_COLOR);
  return;
}
void Tile::setEndTile(){
  state = 'e';
  rect.setFillColor(END_TILE_COLOR);
  return;
}
void Tile::setPathTile(){
  state = 'p';
  rect.setFillColor(PATH_COLOR);
  return;
}

void Tile::setPosition(int x, int y){
  posx = x;
  posy = y;
  rect.setPosition(posx, posy);
  return;
}

void Tile::update(sf::RenderWindow *window){
  window->draw(rect);
  return;
}
