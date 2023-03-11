#ifndef WORLD_HPP
#define WORLD_HPP

/**
   This file declares the World class which contains all the information about
   the scene - geometry and materials, lights, viewplane, camera, samplers, and
   acceleration structures.

   It also traces rays through the scene.

   Courtesy Kevin Suffern.
*/

#include <vector>

#include "../geometry/Geometry.hpp"
#include "../samplers/Sampler.hpp"
#include "../utilities/RGBColor.hpp"
#include "ViewPlane.hpp"

class Camera;
class Geometry;
class Ray;
class Sampler;
class ShadeInfo;
class Normal;

class World {
public:

    ViewPlane               vplane;
    RGBColor                bg_color;
    std::vector<Geometry *> geometry;
    Camera                 *camera_ptr;
    Sampler                *sampler_ptr;

public:

    World();

    ~World();

    void add_geometry(Geometry *);
    void set_camera(Camera *);

    void build();

    ShadeInfo hit_objects(const Ray &);
};

#endif
