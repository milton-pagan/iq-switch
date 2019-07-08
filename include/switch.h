#pragma once

class Switch {
 private:
  int n;

 public:
  int switch_matrix[1024][1024];

  Switch(int n);
  void add_arrival(int i, int j);
  int get_size();
};
