#pragma once

#include <vector>
#include <string>

#include "abstract_data_object.h"
#include "core/optional.h"

namespace hovertaxi {

class AbstractDataStorage {
 public:
  virtual Optional<AbstractDataObject> LoadObjectById(const std::string &collection,
                                                      const std::string &id) const = 0;
  virtual std::vector<AbstractDataObject> LoadObjects(const std::string &collection) const = 0;
};

}