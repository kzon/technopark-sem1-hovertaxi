#pragma once

#include <vector>

#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>

#include "models/Aircraft.h"

template <class T>
using optional = bsoncxx::stdx::optional<T>;

namespace services {

class DataManager {
 public:
  DataManager(const DataManager &) = delete;
  DataManager &operator=(DataManager &) = delete;

  static DataManager &GetInstance(const std::string &uri);

  optional<models::Aircraft> LoadAircraftById(std::string id) const;
 private:
  explicit DataManager(const std::string &uri) : instance_(), uri_(uri), client_(uri_) {}

  mongocxx::database GetDatabase() const;

  mongocxx::collection GetAircraftCollection() const;

  models::Aircraft ConvertAircraftToModel(bsoncxx::document::value &aircraft) const;

  mongocxx::instance instance_;
  mongocxx::uri uri_;
  mongocxx::client client_;

  const std::string database_name_ = "hovertaxi";
};

}