#pragma once
#include <vector>
#include <algorithm>
#include "../include/temp_functions.h"

class HungarianAlgorithm {
 public:

  int** find_matching(int **arr, int size);

 private:

  int row_max(int **arr, int row, int size);
  int col_max(int **arr, int col, int size);
  void copy_array(int **arr,int **new_arr, int size);
  bool check_opt_assign(int **arr, int size);

};
