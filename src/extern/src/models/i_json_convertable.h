#pragma once

#include <map>

namespace hovertaxi {

class IJsonConvertable {
 public:
  virtual std::map<std::string, std::string> GetJsonFields() const = 0;
};

}