#ifndef SIMPLE_HPP
#define SIMPLE_HPP

/**
   This file declares the Simple class which represents a simple sampler.

   It shoots a single ray of weight 1 through a pixel.

   Courtesy Kevin Suffern.
*/

#include "Sampler.hpp"

class Simple : public Sampler {
    public:

        Simple() = default;
        Simple(Camera *, ViewPlane *);
        Simple(const Simple &);

        Simple &operator=(const Simple &);

        std::vector<Ray> get_rays(int, int) const override;
};

#endif