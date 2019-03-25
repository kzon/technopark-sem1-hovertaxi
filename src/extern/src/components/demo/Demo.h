#pragma once

#include <vector>

#include "models/State.h"
#include "models/GeoPoint.cpp"
#include "models/Order.cpp"
#include "db/DbManager.h"

namespace components {

	class Demo {
	public:	
		Demo(models::GeoPoint c, double r): center(c), radius(r), count_vehicles(10) {}

		//if user doesn't select special vehicle
		std::vector<models::Vehicle> generateAllVehicles();

		//if user select special vehicle
		std::vector<models::Vehicle> generateSpecVehicles(long long vehicle_id);

		//here should be also type of vehicle, 
		//returns a driver with nearest point and needed model  
		models::Vehicle getNearestVehicle(models::GeoPoint c);

		void resetArea(models::GeoPoint c, double r);

		//this method should be restarted every n miliseconds 
		//and update position of each vehicle in orders
		std::vector<models::Order> updatePositions();

		void addNewOrder(models::Order order);
		void cancelOrder(models::Order order);

	private:
		int count_vehicles;

		//these two parameteres for limit area on map
		models::GeoPoint center;
		double radius; 

		std::vector<models::Order> orders;

		DbManager &db;
	};
}