#include "BFS.h"
#include "grid.h"
#include "window_config.h"
#include "colors.h"

#include <SFML/Graphics.hpp>
#include <queue>
#include <utility>

#include <iostream>

#define ff first
#define ss second

using namespace std;

BFS_struct::BFS_struct(int size_x, int size_y){
  sizex = size_x;
  sizey = size_y;

  prev_mat = new pair<int, int>[sizey*sizex];

  for(int i = 0; i < sizey; i++){
    for(int j = 0; j < sizex; j++){
      prev_mat[(i*sizex)+j] = {-1, -1};
    }
  }

  return;
}

void BFS_struct::start(){
  run_alg = true;
  if(q.empty()) q.push(start_point);
  return;
}

bool BFS_struct::running(){
  return run_alg;
}

void BFS_struct::pause(){
  run_alg = false;
  return;
}

void BFS_struct::clear(){
  while(!q.empty()){
    q.pop();
  }
  start_point = {-1, -1};
  end_point = {-1, -1};
  cnt_pace = 0;
  run_alg = false;
  return;
}

void BFS_struct::show_min_path(Grid *board, pair<int, int> cur_node){
  while(prev_mat[(cur_node.ss*sizex)+cur_node.ff].ff != -1){
    board->setPathTile(cur_node.ff, cur_node.ss);
    cur_node = prev_mat[(cur_node.ss*sizex)+cur_node.ff];
  }
  return;
}

void BFS_struct::run(Grid *board){
  if(!q.empty()){
    pair<int, int> cur_node = q.front();
    q.pop();

    for(int i=0; i<4; i++){
      pair<int, int> nxt_node = {cur_node.ff+dirx[i], cur_node.ss+diry[i]};
      if(nxt_node.ff < 0 || nxt_node.ss >= board->sizex) continue;
      if(nxt_node.ss < 0 || nxt_node.ss >= board->sizey) continue;
      if(nxt_node == end_point){
        show_min_path(board, cur_node);
        pause();
        return;
      }
      if(board->getState(nxt_node.ff, nxt_node.ss) != 'a') continue;

      q.push(nxt_node);
      board->setProcessing(nxt_node.ff, nxt_node.ss);
      prev_mat[(nxt_node.ss*sizex)+nxt_node.ff] = cur_node;
    }
  }
  return;
}
