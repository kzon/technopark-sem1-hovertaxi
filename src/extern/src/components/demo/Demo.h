#pragma once

#include <vector>

#include "models/State.h"
#include "models/GeoPoint.h"
#include "db/DbManager.h"

namespace components {

	class Demo {
	public:	
		Demo(models::GeoPoint _from, models::GeoPoint _to): from(_from), to(_to), count_vehicles(10) {}

		//if user doesn't select special vehicle
		std::vector<models::Vehicle> generateAllVehicles();

		//if user select special vehicle
		std::vector<models::Vehicle> generateSpecVehicles(long long vehicle_id);

		models::Vehicle getNearestVehicle();

	private:
		int count_vehicles;

		models::GeoPoint from, to; 

		models::Vehicle cur_vehicle;

		DbManager &db;
	};
}