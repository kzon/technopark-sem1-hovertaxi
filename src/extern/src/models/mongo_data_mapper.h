#pragma once

#include <string>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <mongocxx/stdx.hpp>

#include "i_json_convertable.h"
#include "services/data_manager/data_storage/mongo_data_object.h"

namespace hovertaxi {

class MongoDataMapper : public IJsonConvertable {
 public:
  std::string id;

  MongoDataMapper() = default;
  explicit MongoDataMapper(const MongoDataObject &object) {
    auto data = object.data;
    this->id = data["_id"].get_oid().value.to_string();
  };

  static std::string GetSource() { return ""; };

  std::map<std::string, std::string> GetJsonFields() const override {
    std::map<std::string, std::string> fields;
    fields["id"] = id;
    return fields;
  }
};

}