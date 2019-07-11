#include <iostream>
#include "../include/switch.h"
#include "../include/sim.h"
#include "../include/temp_functions.h"

using namespace std;

int main() {
  int size = 0;
  int time_slots = 0;
  float epsilon = 0;

  cout << "Enter size: \n";
  cin >> size;

  cout << "Enter number of time slots: \n";
  cin >> time_slots;

  cout << "Enter epsilon: \n";
  cin >> epsilon;

  Switch iq_switch{size};
  Simulation sim{iq_switch, size, epsilon};

  sim.run_sim(time_slots);

  print_2D_array(iq_switch.get_matrix(), iq_switch.get_size());

}
