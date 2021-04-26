// Copyright 2021 Alibekov Murad

#ifndef MODULES_POLYGON_INCLUDE_POLYGON_H_
#define MODULES_POLYGON_INCLUDE_POLYGON_H_

#include <utility>
#include <vector>
#include <cmath>
#include <stdexcept>

using Point2D = std::pair<double, double>;
using Points2D = std::vector<Point2D>;
namespace Polygon {
    double PolygonArea(const Points2D& polygon);
}

#endif  // MODULES_POLYGON_INCLUDE_POLYGON_H_
