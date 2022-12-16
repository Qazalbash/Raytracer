#ifndef SIMPLE_HPP
#define SIMPLE_HPP

/**
   This file declares the Simple class which represents a simple sampler.

   It shoots a single ray of weight 1 through a pixel.

   Courtesy Kevin Suffern.
*/

#include "Sampler.hpp"

class Simple : public Sampler {
protected:

    // add members to cache values to avoid recomputation in get_rays().

public:

    // Constructors.
    Simple() = default;             // initializes members to NULL.
    Simple(Camera *, ViewPlane *);  // set members.

    // Copy constuctor and assignment operator.
    Simple(const Simple &);
    Simple &operator=(const Simple &);

    // Shoot a ray of weight 1 through the center of the pixel.
    std::vector<Ray> get_rays(int, int) const override;
};

#endif  // SIMPLE_HPP