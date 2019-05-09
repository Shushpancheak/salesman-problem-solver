#pragma once

#include <unordered_map>

template<typename T, T DefaultValue = T()>
class Dsu {
 public:
  explicit Dsu();
  ~Dsu();

  T FindLeader(const T& elem);
  void MakeSet(const T& elem);
  bool UniteSets(const T& first, const size_t& second);

 private:
  std::unordered_map<T, T> parent_;
  std::unordered_map<T, size_t> rank_;
};
