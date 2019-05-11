#include <iostream>
#include "SalesmanProblem/SalesmanProblemExperimenter.hpp"
#include <ctime>

int main() {
  srand(time(nullptr));
  SalesmanProblemExperimenter experimenter;

  for (size_t i = 3; i < 10; ++i) {
    experimenter.Experiment(i, 5);
  }

  return 0;
}
