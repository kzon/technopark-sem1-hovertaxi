#include "data_filter_condition.h"

namespace hovertaxi {

void DataFilterCondition::StringEquals(DataFilter &filter, const std::string &field, const std::string &value) {
  filter << field << value;
}

void DataFilterCondition::GeoPointInRadius(DataFilter &filter,
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

}