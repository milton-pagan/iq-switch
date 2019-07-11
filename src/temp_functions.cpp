#include "../include/temp_functions.h"

void print_2D_array(int **arr, int size) {
  for(int i =0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      std::cout << arr[i][j]
           << " ";
    }
    std::cout << "\n";
  }

  std::cout << "\n";
}
