#pragma once

#include "models/Vehicle.cpp"

namespace components {
	class DbManager {
	public: 
		std::vector<models::Vehicle> getAllVehicles(int *error);
		models::Vehicle getVehicleById(long long id, int *error);

	private:
		
	};
}