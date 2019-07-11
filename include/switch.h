#pragma once

class Switch {
 private:
  int size;
  int **switch_matrix = nullptr;

 public:
  Switch(int n);
  void add_arrival(int i, int j, int arrivals);
  int get_size();
  int** get_matrix();
};
