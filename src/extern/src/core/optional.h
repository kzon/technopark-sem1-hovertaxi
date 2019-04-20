#pragma once

#include <bsoncxx/json.hpp>

namespace hovertaxi {

template<class T>
using Optional = bsoncxx::stdx::optional<T>;

}