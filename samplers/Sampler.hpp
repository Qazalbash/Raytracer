#ifndef SAMPLER_HPP
#define SAMPLER_HPP

/**
   This file declares the Sampler class which is an abstract class for concrete
   samplers to inherit from.

   A sampler samples a scene by shooting primary rays through pixels in a
   viewplane. A primary ray begins at the pixel and its direction is determined
   by a camera. Different samplers shoot different numbers of primary rays in
   different manners.

   Courtesy Kevin Suffern.
*/

#include <vector>

#include "../cameras/Camera.hpp"
#include "../utilities/Ray.hpp"
#include "../world/ViewPlane.hpp"

class Camera;
class Ray;
class ViewPlane;

class Sampler {
protected:

    Camera    *camera_ptr;
    ViewPlane *viewplane_ptr;

public:

    Sampler();
    Sampler(Camera *, ViewPlane *);
    Sampler(const Sampler &) = default;

    Sampler &operator=(const Sampler &) = default;

    virtual std::vector<Ray> get_rays(int, int) const = 0;
};

#endif