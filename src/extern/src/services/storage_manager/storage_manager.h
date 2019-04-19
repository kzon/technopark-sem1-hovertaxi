#pragma once

#include "../data_storage/mongo_data_storage.h"
#include "../data_converter/mongo_data_converter.h"

namespace hovertaxi {

class StorageManager{

 public:

  static StorageManager &GetInstance(const std::string &uri);

  core::optional<Aircraft> LoadAircraftById(const std::string &id) const;
  std::vector<AircraftClass> LoadAircraftClasses() const;

  std::string LoadAircraftClassesAsJSON() const;
  std::string LoadAircraftByIdAsJSON(const std::string &id) const;

private:
  explicit StorageManager(const std::string &uri) : db_(uri) {}

  MongoDataStorage db_;
  MongoDataConverter db_converter;

  const std::string AIRCRAFT_COLLECTION_NAME = "aircraft";
  const std::string AIRCRAFT_CLASS_COLLECTION_NAME = "aircraft_class";

};

}