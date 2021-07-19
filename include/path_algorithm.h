#ifndef PATH_ALGORITHM_H
#define PATH_ALGORITHM_H

#include "grid.h"
#include <utility>

class PathAlgorithm{
protected:
  int dirx[4] = {1, -1, 0, 0};
  int diry[4] = {0, 0, 1, -1};
  int cnt_pace = 0;
  bool run_alg = false;

public:
  int pace = 1;
  std::pair<int, int> start_point = {-1, -1};
  std::pair<int, int> end_point = {-1, -1};

  void upd_start_point(int x, int y);
  void upd_end_point(int x, int y);
  void check_point_edited(int x, int y);

  virtual void start() = 0;
  virtual bool running() = 0;
  virtual void pause() = 0;
  virtual void run(Grid *board) = 0;
  virtual void clear() = 0;
};

#endif
