#ifndef VIEWPLANE_HPP
#define VIEWPLANE_HPP

/**
   This file declares the ViewPlane class which represents a view plane.

   The view plane shares the world's coordinate system. x increases rightward,
   and y upward.

   Courtesy Kevin Suffern.
*/

#include "../utilities/Point3D.hpp"
#include "../utilities/Vector3D.hpp"

class ViewPlane {
    public:

        Point3D  top_left, bottom_right;
        Vector3D normal;
        int      hres, vres;

        ViewPlane();

        ViewPlane(const ViewPlane &)            = default;
        ViewPlane &operator=(const ViewPlane &) = default;

        int  get_hres() const;
        void set_hres(int);
        int  get_vres() const;
        void set_vres(int);

        ~ViewPlane() = default;
};

#endif