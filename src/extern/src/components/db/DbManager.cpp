#pragma once

#include "DbManager.h"

namespace components {
	std::vector<models::Vehicle> DbManager::getAllVehicles(int *error){
		return std::vector<models::Vehicle> vehicles;
	}
	
	models::Vehicle DbManager::getVehicleById(long long id, int *error){
		return models:Vehicle v{};
	}
}