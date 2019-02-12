
#ifndef POLYLABELFAST
#define POLYLABELFAST
#define _USE_MATH_DEFINES

#include <vector>
#include <tuple>
#include <iostream>

#include <mapbox/geometry/point.hpp>
#include <mapbox/geometry/polygon.hpp>
#include "polylabel.hpp"

#include "pybind11/pybind11.h" // Pybind11 import to define Python bindings
#include "pybind11/stl.h"      // Pybind11 import for STL containers
#include <pybind11/stl_bind.h> // Pybind11 stl bindings

namespace polylabelfast {

    using pointD = mapbox::geometry::point<double>;
    using point2 = std::array<double,2>;

    using ringD = std::vector<point2>;
    using ringsD = std::vector<ringD>;

    std::tuple<point2, double> polylabelfast(std::vector<std::vector<point2>> rings, double precision);
    
}


#endif
