#pragma once

#include <string>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <mongocxx/stdx.hpp>

#include "services/data_manager/data_storage/mongo_data_object.h"

namespace hovertaxi {

class MongoDataMapper {
 public:
  std::string id;

  MongoDataMapper() = default;
  explicit MongoDataMapper(const MongoDataObject &object) {
    auto data = object.data;
    this->id = data["_id"].get_oid().value.to_string();
  };

  static std::string GetSource() { };
};

}