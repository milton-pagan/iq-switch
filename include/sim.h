#pragma once
#include "../include/switch.h"
#include <random>

class Simulation {
 private:
  int num_arrivals;
  Switch& iq_switch;
  std::random_device rd;
  std::mt19937 gen;
  std::poisson_distribution<> poi;
  std::uniform_int_distribution<int> unif;

 public:
  Simulation(Switch& iq_switch, int size);

  void gen_arrivals();
};
