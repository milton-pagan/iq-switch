#pragma once

#include "../include/switch.h"
#include <random>
#include "../include/max_weight.h"


class Simulation {
 private:
  int num_arrivals;
  int size;

  Switch& iq_switch;

  std::random_device rd;
  std::mt19937 gen;
  std::poisson_distribution<> poi;
  std::uniform_int_distribution<int> unif;

  HungarianAlgorithm hun_alg;

  void gen_arrivals();

 public:
  Simulation(Switch& iq_switch, int size, float epsilon);

  void run_sim(int time_slots);
};
