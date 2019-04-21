#pragma once

#include <utility>
#include <bsoncxx/builder/stream/document.hpp>

namespace hovertaxi {

class MongoDataObject {
 public:
  MongoDataObject(const bsoncxx::document::view &d) : data(d) {};
  bsoncxx::document::view data;
};

}