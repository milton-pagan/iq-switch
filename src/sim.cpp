#include "../include/sim.h"

using namespace std;

//Constructor
Simulation:: Simulation(Switch& iq, int sz, float epsilon):iq_switch{iq}, gen{rd()}
                                           , size{sz}
                                           , poi{(1-epsilon)/sz}
                                           , unif{0, size - 1} {}
//Member functions
void Simulation:: run_sim(int time_slots) {
  for(int i = 0; i < time_slots; i++) {
    gen_arrivals();
    hun_alg.find_matching(iq_switch.get_matrix(), iq_switch.get_size());
  }
}

//Generates random (i,j) and adds arrival
void Simulation:: gen_arrivals() {
  for(int i = 0; i < iq_switch.get_size(); i++) {
    for(int j = 0; j < iq_switch.get_size(); j++) {
      iq_switch.add_arrival(i, j, poi(gen));
    }
  }
}
