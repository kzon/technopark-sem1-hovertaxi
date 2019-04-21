#pragma once

#include <sstream>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>

#include "services/data_manager/data_storage/mongo_data_object.h"

namespace hovertaxi {

class MongoDataConverter {
 public:
  std::string ToJSON(const MongoDataObject &object) const;
  std::string ToJSON(const std::vector<MongoDataObject> &objects) const;
};

}