#pragma once

#include <utility>
#include <bsoncxx/builder/stream/document.hpp>

#include "services/data_manager/data_storage/abstract/abstract_data_object.h"

namespace hovertaxi {

class MongoDataObject : public AbstractDataObject {
 public:
  MongoDataObject(bsoncxx::document::value d) : data(std::move(d)) {};
  bsoncxx::document::value data;
};

}