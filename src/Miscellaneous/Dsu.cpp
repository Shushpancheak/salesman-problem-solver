#include "Dsu.hpp"

template <typename T, T DefaultValue>
Dsu<T, DefaultValue>::Dsu()
  : parent_()
  , rank_() {}

template <typename T, T DefaultValue>
Dsu<T, DefaultValue>::~Dsu() = default;

template <typename T, T DefaultValue>
T Dsu<T, DefaultValue>::FindLeader(const T& elem) {
  if (parent_.find(elem) == parent_.end()) {
    return DefaultValue;
  }
  if (parent_[elem] == elem) {
    return elem;
  }

  return parent_[elem] = FindLeader(parent_[elem]);
}

template <typename T, T DefaultValue>
void Dsu<T, DefaultValue>::MakeSet(const T& elem) {
  parent_[elem] = elem;
  rank_[elem] = 0;
}

template <typename T, T DefaultValue>
bool Dsu<T, DefaultValue>::UniteSets(const T& first, const size_t& second) {
  T leader1 = FindLeader(first);
  T leader2 = FindLeader(second);

  if (leader1 != leader2) {
    if (rank_[leader1] < rank_[leader2]) {
      std::swap(leader1, leader2);
    }
    parent_[leader2] = leader1;
    if (rank_[leader1] == rank_[leader2]) {
      ++rank_[leader1];
    }
    return true;
  }
  return false;
}
