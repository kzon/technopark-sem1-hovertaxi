#pragma once

#include "models/i_json_convertable.h"
#include "models/aircraft_class.h"
#include "models/aircraft.h"
#include "models/pad.h"
#include "models/route.h"

namespace hovertaxi {

class ApiOrder : public IJsonConvertable {
 public:
  std::string status;
  Pad from_pad, to_pad;
  AircraftClass aircraft_class;
  Aircraft assigned_aircraft;
  AircraftModel assigned_aircraft_model;
  int time_to_arrival;
  Route route;
  int price;

  std::map<std::string, std::string> GetJsonFields() const override {
    std::map<std::string, std::string> fields;
    fields["status"] = status;
    fields["from_pad"] = JSON::ToJSON(from_pad, true);
    fields["to_pad"] = JSON::ToJSON(to_pad, true);
    fields["aircraft_class"] = JSON::ToJSON(aircraft_class, true);
    fields["assigned_aircraft"] = JSON::ToJSON(assigned_aircraft, true);
    fields["assigned_aircraft_model"] = JSON::ToJSON(assigned_aircraft_model, true);
    fields["time_to_arrival"] = std::to_string(time_to_arrival);
    fields["route"] = JSON::ToJSON(route, true);
    fields["price"] = std::to_string(price);
    return fields;
  }
};

}