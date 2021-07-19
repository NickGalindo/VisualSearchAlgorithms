#include "path_algorithm.h"

#include <utility>

using namespace std;

void PathAlgorithm::upd_start_point(int x, int y){
  start_point = {x, y};
  if(end_point == make_pair(x, y)) end_point = {-1, -1};
  return;
}

void PathAlgorithm::upd_end_point(int x, int y){
  end_point = {x, y};
  if(start_point == make_pair(x, y)) start_point = {x, y};
  return;
}

void PathAlgorithm::check_point_edited(int x, int y){
  if(start_point == make_pair(x, y)) start_point = {-1, -1};
  if(end_point == make_pair(x, y)) end_point = {-1, -1};
  return;
}
