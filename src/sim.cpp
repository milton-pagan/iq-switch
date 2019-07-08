#include "../include/sim.h"

using namespace std;

//Constructor
Simulation:: Simulation(Switch& iq, int size):iq_switch{iq}, gen{rd()}
                                                           , poi{1}
                                                           , unif{0, size - 1} {}

//Generates random (i,j) and adds arrival
void Simulation:: gen_arrivals() {
  int i, j;
  int arrivals {poi(gen)};

  for(int n = 0; n < arrivals; n++) {
    i = unif(gen);
    j = unif(gen);

    iq_switch.add_arrival(i, j);
  }
}
