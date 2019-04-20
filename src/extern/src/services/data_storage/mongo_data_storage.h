#pragma once

#include <vector>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>

#include "abstract_data_storage.h"

namespace hovertaxi {

typedef bsoncxx::document::view View;
typedef bsoncxx::document::value Value;

class MongoDataStorage : public AbstractDataStorage<Value, View> {

 public:

  explicit MongoDataStorage(const std::string &uri) :
      instance_(),
      uri_(uri),
      client_(uri_),
      db_(client_[DB_NAME]) {}

  core::optional<Value> LoadObjectById(const std::string &collection, const std::string &id) const override;
  std::vector<View> LoadObjects(const std::string &collection) const override;

 private:
  mongocxx::collection GetCollection(const std::string &name) const;

  mongocxx::instance instance_;
  mongocxx::uri uri_;
  mongocxx::client client_;
  mongocxx::database db_;

  static constexpr const char *DB_NAME = "hovertaxi";

};

}