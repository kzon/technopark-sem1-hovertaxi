#pragma once

#include "DataMapper.h"

namespace models {

enum OrderStatus {
  NEW,
  PROCESSING,
  AIRCRAFT_ASSIGNED,
  ON_FLY,
  FINISHED,
  CANCELED,
  PROCESS_TIMEOUT,
};

struct Order : public DataMapper {
  std::string user_id;
  OrderStatus status;
  std::string from_pad_id, to_pad_id;
  std::string aircraft_class_id;
  std::string assigned_aircraft_id;
  std::string route_id;
  int price;
};

}