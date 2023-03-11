#ifndef SIMPLE_HPP
#define SIMPLE_HPP

/**
   This file declares the Simple class which represents a simple sampler.

   It shoots a single ray of weight 1 through a pixel.

   Courtesy Kevin Suffern.
*/

#include "Sampler.hpp"

class Anti_Alias_Sampler : public Sampler {
public:

    Anti_Alias_Sampler() = default;
    Anti_Alias_Sampler(Camera *, ViewPlane *);
    Anti_Alias_Sampler(const Anti_Alias_Sampler &);

    Anti_Alias_Sampler &operator=(const Anti_Alias_Sampler &);

    std::vector<Ray> get_rays(int px, int py) const override;
};

#endif