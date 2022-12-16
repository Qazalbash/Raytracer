//  Credit: Matthew Calligaro <matthewcalligaro@hotmail.com>

#include "../cameras/Parallel.hpp"
#include "../geometry/Plane.hpp"
#include "../geometry/Sphere.hpp"
#include "../geometry/Triangle.hpp"
#include "../materials/Cosine.hpp"
#include "../samplers/Anti_Alias_Sampler.hpp"
#include "../utilities/Constants.hpp"
#include "../world/World.hpp"

void World::build(void) {
    // View plane  .
    int n                 = 10;
    vplane.top_left.x     = -n;
    vplane.top_left.y     = n;
    vplane.top_left.z     = 10;
    vplane.bottom_right.x = n;
    vplane.bottom_right.y = -n;
    vplane.bottom_right.z = 10;
    vplane.hres           = 400;
    vplane.vres           = 400;

    // Background color.
    bg_color = grey;

    // Camera and sampler.
    set_camera(new Parallel(0, 0, -1));
    sampler_ptr = new Anti_Alias_Sampler(camera_ptr, &vplane);

    for (int x = -8; x <= 8; x += 2) {
        for (int y = -8; y <= 8; y += 2) {
            Sphere* s = new Sphere(Point3D(x, y, 0), 1);
            s->set_material(new Cosine((x + 8.0) / 16.0, 0, (y + 8.0) / 16.0));
            add_geometry(s);
        }
    }
}
