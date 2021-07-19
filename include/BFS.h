#ifndef BFS_H
#define BFS_H

#include "path_algorithm.h"
#include "grid.h"
#include <queue>
#include <utility>

class BFS_struct : public PathAlgorithm {
private:
  int sizex, sizey;
  std::queue<std::pair<int, int> > q;
  std::pair<int, int> *prev_mat;
  void show_min_path(Grid *board, std::pair<int, int> cur_node);

public:
  BFS_struct(int size_x, int size_y);
  void start();
  bool running();
  void pause();
  void run(Grid *board);
  void clear();
};

#endif
