#pragma once

#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>

#include "models/Aircraft.h"

namespace services {

template<class T>
using optional = bsoncxx::stdx::optional<T>;

class Database {
 public:
  explicit Database(const std::string &uri) :
      instance_(),
      uri_(uri),
      client_(uri_),
      db_(client_[DB_NAME]) {}

  optional<bsoncxx::document::value> LoadObjectById(const std::string &collection, const std::string &id) const;
  std::string ToJSON(const bsoncxx::document::value &object) const;

  models::Aircraft ConvertAircraftToModel(bsoncxx::document::value &document) const;

 private:
  mongocxx::collection GetCollection(const std::string &name) const;

  mongocxx::instance instance_;
  mongocxx::uri uri_;
  mongocxx::client client_;
  mongocxx::database db_;

  static constexpr const char *DB_NAME = "hovertaxi";
};

}