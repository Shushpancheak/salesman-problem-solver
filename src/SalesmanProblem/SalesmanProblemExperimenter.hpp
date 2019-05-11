#pragma once

#include <iostream>
#include "SalesmanProblemBuilder.hpp"

class SalesmanProblemExperimenter {
public:
  void Experiment(size_t vertices_count, size_t experiments_count,
                  double width = 1.0, double height = 1.0) const;
};