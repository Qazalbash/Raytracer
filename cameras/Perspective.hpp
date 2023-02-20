#ifndef PERSPECTIVE_HPP
#define PERSPECTIVE_HPP

/**
   This file declares the Perspective class which represents a perspective
   viewing camera.

   Courtesy Kevin Suffern.
*/

#include "../utilities/Point3D.hpp"
#include "Camera.hpp"

class Vector3D;

class Perspective : public Camera {
    protected:

        Point3D pos;

    public:

        Perspective();
        Perspective(float);
        Perspective(float, float, float);
        Perspective(const Point3D &);

        Perspective(const Perspective &);
        Perspective &operator=(const Perspective &);

        virtual Vector3D get_direction(const Point3D &) const;
};

#endif