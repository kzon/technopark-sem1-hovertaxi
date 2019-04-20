#pragma once

#include <vector>
#include <string>

namespace hovertaxi {

template<class Value, class View>
class AbstractDataStorage {

 public:
  virtual core::optional<Value> LoadObjectById(const std::string &collection, const std::string &id) const = 0;

  virtual std::vector<View> LoadObjects(const std::string &collection) const = 0;
};

}