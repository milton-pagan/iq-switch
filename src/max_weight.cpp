#include "../include/max_weight.h"
#include "../include/temp_functions.h"

//Implements Hungarian Algorithm to find max weight assignments
int** HungarianAlgorithm::find_matching(int **arr, int size) {
  //Make a modifiable copy of the array
  int **new_arr = new int*[size];
  int **result = new int*[size];

  for(int i = 0; i < size; i++) {
    new_arr[i] = new int[size];
    result[i] = new int[size];
  }

  copy_array(arr, new_arr, size);

  //Rows
  for(int i = 0; i < size; i++) {
    int max = row_max(new_arr, i, size);
    for(int j = 0; j < size; j++) {
      new_arr[i][j] -= max;
    }
  }

  check_opt_assign(new_arr, size);

  delete[] new_arr;
  return result;
}

//Checks if an optimal assignment can be made
bool HungarianAlgorithm::check_opt_assign(int **arr, int size) {
  std::vector<int> assigned_rows;
  std::vector<int> assigned_columns;

  //Assign non-colliding zeros
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      if(arr[i][j] == 0 && std::find(assigned_rows.begin(), assigned_rows.end(), i)
         == assigned_rows.end()
         && std::find(assigned_columns.begin(), assigned_columns.end(), j)
         == assigned_columns.end()) {

        assigned_rows.insert(assigned_rows.end(),i);
        assigned_columns.insert(assigned_columns.end(),j);
        break;
      }
    }
  }

  //DEBUG
  std::cout << "rows\n";
  print_vector(assigned_rows);
  std::cout << "\n";
  std::cout << "cols\n";
  print_vector(assigned_columns);
  std::cout << "\n";

  std::vector<int> marked_rows;
  std::vector<int> marked_columns;

  //Mark unassigned rows
  for(int i = 0; i < size; i++) {
    if(std::find(assigned_rows.begin(), assigned_rows.end(), i) == assigned_rows.end())
      marked_rows.insert(marked_rows.end(), i);
  }

  //DEBUG
  std::cout << "marked rows\n";
  print_vector(marked_rows);
  std::cout << "\n";

  //Mark columns having zeros in marked rows
  for(int i = 0; i < assigned_rows.size(); i++) {
    if(std::find(marked_rows.begin(), marked_rows.end(), assigned_rows[i]) != marked_rows.end())
      marked_columns.insert(marked_columns.end(), assigned_columns[i]);
  }

  //DEBUG
  std::cout << "marked columns\n";
  print_vector(marked_columns);
  std::cout << "\n";


  //Mark rows having zeros in marked columns
  for(int i = 0; i < assigned_columns.size(); i++) {
    if(std::find(marked_columns.begin(), marked_columns.end(), assigned_columns[i])
       != marked_columns.end())
      marked_rows.insert(marked_rows.end(), assigned_rows[i]);
  }

  //DEBUG
  std::cout << "marked rows 2\n";
  print_vector(marked_rows);
  std::cout << "\n";


}

int HungarianAlgorithm::row_max(int **arr, int row, int size) {
  int max = arr[row][0];

  for(int i = 1; i < size; i++) {
    if(arr[row][i] > max) {
      max = arr[row][i];
    }
  }

  return max;
}

int HungarianAlgorithm::col_max(int **arr, int col, int size) {
  int max = arr[0][col];

  for(int i = 1; i < size; i++) {
    if(arr[i][col] > max) {
      max = arr[i][col];
    }
  }

  return max;
}

void HungarianAlgorithm::copy_array(int **arr,int **new_arr, int size) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      new_arr[i][j] = arr[i][j];
    }
  }
}
