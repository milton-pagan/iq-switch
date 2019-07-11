#include "../include/switch.h"


//Constructor
Switch::Switch(int n) {
  size = n;
  switch_matrix = new int*[n];

  for(int i = 0; i < n; i++) {
    switch_matrix[i] = new int[n];
  }
}

//Member functions

void Switch::add_arrival(int i, int j, int arrivals) {
  switch_matrix[i][j] += arrivals;
}

int Switch::get_size() {
  return size;
}

int** Switch::get_matrix() {
  return switch_matrix;
}
