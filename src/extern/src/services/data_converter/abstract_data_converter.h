#pragma once

#include <string>
#include <vector>

namespace hovertaxi{

template <class Value, class View>
class AbstractDataConverter{

 public:

  virtual std::string ToJSON(const View &obj) const = 0;
  virtual  std::string ToJSON(const std::vector<View> &objs) const  = 0;

};

}