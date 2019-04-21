#include "mongo_data_converter.h"

namespace hovertaxi {

std::string MongoDataConverter::ToJSON(const MongoDataObject &object) const {
  return bsoncxx::to_json(object.data);
}

std::string MongoDataConverter::ToJSON(const std::vector<MongoDataObject> &objects) const {
  std::ostringstream result;
  bool is_first = true;
  result << '[';
  for (const auto &object : objects) {
    if (!is_first)
      result << ',';
    result << ToJSON(object);
    is_first = false;
  }
  result << ']';
  return result.str();
}

}