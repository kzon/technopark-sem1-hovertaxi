#include "Demo.h"

namespace components {
	std::vector<models::Vehicle> Demo::generateAllVehicles()  {
		int error = 0;
		std::vector<models::Vehicle> vehiclesFromDb = db.getAllVehicles(&error);
		size_t size = vehiclesFromDb.size();

		std::vector<models::Vehicle> result;

		if(!error){
			//todo generate GeoPoint in certaion area
			//and set it to vehicle
			for(int i = 0; i < count_vehicles; i++){			
				int index = rand() % size;
				result.push_back(vehiclesFromDb[index]);
			}
		}		

		return result;
	}

	std::vector<models::Vehicle> Demo::generateSpecVehicles(long long vehicle_id){
		int error = 0;

		std::vector<models::Vehicle> result;

		models::Vehicle v = db.getVehicleById(vehicle_id, &error);

		if(!error){
			//todo generate GeoPoint in certaion area 
			//and set it to vehicle
			for(int i = 0; i < count_vehicles; i++){			
				result.push_back(v);
			}
		}

		return result;
	}

	models::Vehicle Demo::getNearestVehicle(){
		models::Vehicle v;
		return v;
	}
}