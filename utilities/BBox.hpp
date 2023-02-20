#ifndef BBOX_HPP
#define BBOX_HPP

/**
   This file declares BBox class which represents an axis-aligned bounding box
   defined by 2 points containing the min and max values respectively of x, y,
   and z.
*/

#include "../geometry/Geometry.hpp"
#include "Constants.hpp"
#include "Point3D.hpp"
#include "Ray.hpp"

class Geometry;
class Ray;

class BBox {
    public:

        Point3D pmin, pmax;

    public:

        BBox() = default;
        BBox(const Point3D&, const Point3D&);
        BBox(const BBox&) = default;

        ~BBox() = default;

        BBox& operator=(const BBox&) = default;

        std::string to_string() const;

        bool hit(const Ray&, float&, float&) const;

        void extend(Geometry*);
        void extend(const BBox&);

        bool contains(const Point3D&);

        bool overlaps(Geometry*);
        bool overlaps(const BBox&);
};

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

inline float max_element(float a, float b, float c) { return MAX(MAX(a, b), c); }

inline float min_element(float a, float b, float c) { return MIN(MIN(a, b), c); }

#endif