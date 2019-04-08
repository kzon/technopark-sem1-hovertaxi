#pragma once

#include "Route.h"

namespace components {

models::Route Route::GetRoute(const models::Order &order) {
  return {};
}

std::vector<models::Route> Route::GetCrossingRoutes(const models::Route &route) {
  return std::vector<models::Route>();
}

}