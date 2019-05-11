#include <iostream>
#include "SalesmanProblem/SalesmanProblemExperimenter.hpp"
#include <ctime>

int main() {
  srand(time(nullptr));

  int chosen_method = -1;
  while (!(chosen_method >= 0 && chosen_method <= 1)) {
    std::cout << "Choose method of finding optimal path: (0 - MST with Hamilton Traverse, 1 - Simulated Annealing)" << std::endl;
    std::cin >> chosen_method;
  }

  SalesmanProblemExperimenter experimenter;

  for (size_t i = 3; i < 10; ++i) {
    experimenter.Experiment(i, 5, chosen_method);
  }

  return 0;
}
