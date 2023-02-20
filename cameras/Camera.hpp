#ifndef CAMERA_HPP
#define CAMERA_HPP

/**
   This file declares the Camera class which is an abstract class for concrete
   cameras to inherit from. A camera views the world through a view plane.

   Courtesy Kevin Suffern.
*/

class Point3D;
class Vector3D;

class Camera {
    public:

        Camera() = default;

        Camera(const Camera &)            = default;
        Camera &operator=(const Camera &) = default;

        virtual ~Camera() = default;

        virtual Vector3D get_direction(const Point3D &) const = 0;
};

#endif