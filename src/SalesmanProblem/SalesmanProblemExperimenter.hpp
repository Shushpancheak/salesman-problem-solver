#pragma once

#include <iostream>
#include "SalesmanProblemBuilder.hpp"

class SalesmanProblemExperimenter {
public:
  void Experiment(size_t vertices_count, size_t experiments_count,
                  double width = 100.0, double height = 100.0);
};