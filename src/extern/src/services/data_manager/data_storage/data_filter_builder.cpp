#include "data_filter_builder.h"

namespace hovertaxi {

void DataFilterBuilder::StringEquals(DataFilter &filter, const std::string &field, const std::string &value) {
  filter << field << value;
}

void DataFilterBuilder::GeoPointNear(DataFilter &filter,
                                     const std::string &field,
                                     const GeoPoint &center,
                                     int radius) {
  filter << field << bsoncxx::builder::stream::open_document
         << "$near" << bsoncxx::builder::stream::open_document
         << "$geometry" << bsoncxx::builder::stream::open_document
         << "type" << "Point"
         << "coordinates" << bsoncxx::builder::stream::open_array
         << center.latitude << center.longitude
         << bsoncxx::builder::stream::close_array
         << bsoncxx::builder::stream::close_document
         << "$minDistance" << 0
         << "$maxDistance" << radius
         << bsoncxx::builder::stream::close_document
         << bsoncxx::builder::stream::close_document;
}

void DataFilterBuilder::BoolEquals(DataFilter &filter, const std::string &field, bool value) {
  filter << field << value;
}

void DataFilterBuilder::StringIn(DataFilter &filter,
                                 const std::string &field,
                                 const std::vector<std::string> &values) {
  filter << field << bsoncxx::builder::stream::open_document;
  auto in_array = filter << "$in" << bsoncxx::builder::stream::open_array;
  for (const auto & value : values)
    in_array = in_array << value;
  auto after_array = in_array << bsoncxx::builder::stream::close_array;
  after_array << bsoncxx::builder::stream::close_document;
}

}