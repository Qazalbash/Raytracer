#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include "../materials/Material.hpp"
#include "../utilities/BBox.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"

/**
   This file declares the Geometry class which is an abstract class from which
   other concrete geometric objects will inherit.

   Courtesy Kevin Suffern.
*/

#include <string>

class BBox;
class Material;
class Ray;
class ShadeInfo;

class Geometry {
    protected:

        Material *material_ptr;

    public:

        Geometry();
        Geometry(const Geometry &)            = default;
        Geometry &operator=(const Geometry &) = default;

        virtual ~Geometry() = default;

        virtual std::string to_string() const = 0;

        Material *get_material() const;
        void      set_material(Material *);

        virtual bool hit(const Ray &, float &, ShadeInfo &) const = 0;

        virtual BBox getBBox() const = 0;
};

#endif