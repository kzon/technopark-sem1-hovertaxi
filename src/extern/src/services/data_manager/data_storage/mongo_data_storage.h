#pragma once

#include <algorithm>
#include <sstream>
#include <vector>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>

#include "mongo_data_object.h"
#include "core/optional.h"

namespace hovertaxi {

class MongoDataStorage {
 public:
  explicit MongoDataStorage(const std::string &uri) :
      instance_(),
      uri_(uri),
      client_(uri_),
      db_(client_[DB_NAME]) {}

  Optional<MongoDataObject> LoadObjectById(const std::string &collection, const std::string &id) const;
  std::vector<MongoDataObject> LoadObjects(const std::string &collection) const;

  std::string LoadObjectByIdAsJSON(const std::string &collection, const std::string &id) const;
  std::string LoadObjectsAsJSON(const std::string &collection) const;

 private:
  mongocxx::collection GetCollection(const std::string &name) const;

  std::string ToJSON(const MongoDataObject &object) const;
  std::string ToJSON(const std::vector<MongoDataObject> &objects) const;

  mongocxx::instance instance_;
  mongocxx::uri uri_;
  mongocxx::client client_;
  mongocxx::database db_;

  static constexpr const char *DB_NAME = "hovertaxi";
};

}