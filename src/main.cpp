#include <iostream>
#include "../include/switch.h"
#include "../include/sim.h"
using namespace std;

int main() {
  int size = 0;
  int time_slots = 0;

  cout << "Enter size: \n";
  cin >> size;

  cout << "Enter arrivals: \n";
  cin >> time_slots;

  Switch s{size};
  Simulation sim{s, size};

  for(int i = 0; i < time_slots; i++) {
    sim.gen_arrivals();
  }

  for(int i =0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      cout << s.switch_matrix[i][j]
           << " ";
    }
    cout << "\n";
  }

}
