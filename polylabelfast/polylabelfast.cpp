#include "polylabelfast.hpp"

namespace polylabelfast {

    std::ostream &operator<<(std::ostream &os, const pointD &point)
    {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
    std::ostream &operator<<(std::ostream &os, const std::vector<pointD> &ring)
    {
        os << "[";
        for (auto &&point : ring)
        {
            os << point << ", ";
        }
        os << "]";
        return os;
    }

    std::ostream &operator<<(std::ostream &os, const point2 &point)
    {
        os << "(" << point[0] << ", " << point[1] << ")";
        return os;
    }

    std::ostream &operator<<(std::ostream &os, const ringD &ring)
    {
        os << "[";
        for (auto &&point : ring)
        {
            os << point << ", ";
        }
        os << "]";
        return os;
    }

    std::ostream &operator<<(std::ostream &os, const ringsD &rings)
    {
        os << "[";
        for (auto &&ring : rings)
        {
            os << ring << ", " << std::endl;
        }
        os << "]";
        return os;
    }

    std::tuple<point2, double> polylabelfast(ringsD rings, double precision=1.0) {
        // std::cout << rings;
        point2 pointReturn;
        mapbox::geometry::polygon<double> polygon;
        // convert to mapbox polygon
        // this is a waste but I believe it will go very fast
        for (const auto& ring : rings) {
            mapbox::geometry::linear_ring<double> ringNew;
            for (const auto& point_ : ring) {
                ringNew.push_back({
                    point_[0],
                    point_[1]
                });
            }
            polygon.push_back(std::move(ringNew));
        }
        mapbox::geometry::point<double> pointMapbox;
        double dist = 0.0;
        std::tie(pointMapbox, dist) = mapbox::polylabel(polygon, precision);
        pointReturn[0]= pointMapbox.x;
        pointReturn[1] = pointMapbox.y;

        return std::make_tuple(pointReturn, dist);

    }

}

