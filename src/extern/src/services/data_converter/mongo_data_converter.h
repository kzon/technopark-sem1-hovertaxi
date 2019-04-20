#pragma once

#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <sstream>

#include "abstract_data_converter.h"
#include "models/aircraft.h"
#include "models/aircraft_model.h"
#include "models/order.h"
#include "models/route.h"
#include "models/aircraft_class.h"
#include "models/pad.h"

namespace hovertaxi {

typedef bsoncxx::document::view View;
typedef bsoncxx::document::value Value;

class MongoDataConverter : public AbstractDataConverter<Value, View> {
 public:

  MongoDataConverter() = default;

  template<typename T>
  T ToDataMapper(const View &view) const;

  std::string ToJSON(const View &obj) const override;
  std::string ToJSON(const std::vector<View> &objects) const override;

};

}