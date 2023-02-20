
/**
  This builds a simple scene that consists of a sphere, a triangle, and a
  plane.
  Parallel viewing is used with a single sample per pixel.
*/
#include <time.h>

#include "../cameras/Perspective.hpp"
#include "../geometry/Plane.hpp"
#include "../geometry/Sphere.hpp"
#include "../geometry/Triangle.hpp"
#include "../materials/Cosine.hpp"
#include "../samplers/Anti_Alias_Sampler.hpp"
#include "../utilities/Constants.hpp"
#include "../world/World.hpp"

void World::build(void) {
        srand(time(0));
        // View plane  .
        vplane.top_left.x     = -10.0f;
        vplane.top_left.y     = 10.0f;
        vplane.top_left.z     = 10.0f;
        vplane.bottom_right.x = 10.0f;
        vplane.bottom_right.y = -10.0f;
        vplane.bottom_right.z = 10.0f;
        vplane.hres           = 400;
        vplane.vres           = 400;

        // Background color.
        bg_color = black;

        // Camera and sampler.
        set_camera(new Perspective(0.0f, 0.0f, 20.0f));
        sampler_ptr = new Anti_Alias_Sampler(camera_ptr, &vplane);
        int x, y, c, a, b, r, g;

        for (int i = 0; i < 100; i++) {
                a = rand() % 3;
                if (a == 0) {
                        x = rand() % 41 - 20;
                        y = rand() % 41 - 20;
                        c = rand() % 10;

                        Sphere* sphere_ptr = new Sphere(Point3D(x, y, -20), c);

                        r = rand() % 256;
                        g = rand() % 256;
                        b = rand() % 256;

                        sphere_ptr->set_material(new Cosine(RGBColor(r, g, b)));
                        add_geometry(sphere_ptr);
                }
        }
}
