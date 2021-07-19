#include "grid.h"
#include "tile.h"
#include <SFML/Graphics.hpp>
#include <queue>
#include <utility>

#define ff first
#define ss second

using namespace std;

// Class constructors
Grid::Grid(int x, int y){
  sizex = x;
  sizey = y;

  // Array declared as one-dimensional to optimize memory block creation
  arr = new Tile[sizey*sizex];

  for(int i = 0; i < sizey; i++){
    for(int j = 0; j < sizex; j++){
      arr[(i*sizex)+j].setPosition(j*11, i*11);
    }
  }

  return;
}

//Class functions
void Grid::draw(sf::RenderWindow *window){
  for(int i = 0; i < sizey; i++){
    for(int j = 0; j < sizex; j++){
      arr[(i*sizex)+j].update(window);
    }
  }
  return;
}

void Grid::setOpen(int x, int y){
  arr[(y*sizex) + x].setOpen();
  return;
}
void Grid::setBlocked(int x, int y){
  arr[(y*sizex) + x].setBlocked();
  return;
}
void Grid::setProcessing(int x, int y){
  arr[(y*sizex) + x].setProcessing();
  return;
}
void Grid::setStartTile(int x, int y){
  arr[(y*sizex) + x].setStartTile();
  return;
}
void Grid::setEndTile(int x, int y){
  arr[(y*sizex) + x].setEndTile();
  return;
}
void Grid::setPathTile(int x, int y){
  arr[(y*sizex) + x].setPathTile();
  return;
}

char Grid::getState(int x, int y){
  return arr[(y*sizex) + x].state;
}
