//  Credit: Matthew Calligaro <matthewcalligaro@hotmail.com>

#include "../cameras/Parallel.hpp"
#include "../geometry/Plane.hpp"
#include "../geometry/Sphere.hpp"
#include "../geometry/Triangle.hpp"
#include "../materials/Cosine.hpp"
#include "../samplers/Simple.hpp"
#include "../utilities/Constants.hpp"
#include "../world/World.hpp"

void World::build(void) {
    // View plane
    vplane.top_left.x     = -10.f;
    vplane.top_left.y     = 10.f;
    vplane.top_left.z     = 10;
    vplane.bottom_right.x = 10.f;
    vplane.bottom_right.y = -10.f;
    vplane.bottom_right.z = 10;
    vplane.hres           = 400;
    vplane.vres           = 400;

    // Background color.
    bg_color = grey;

    // Camera and sampler.
    set_camera(new Parallel(0.f, 0.f, -1.f));
    sampler_ptr = new Simple(camera_ptr, &vplane);

    for (int x = -8; x <= 8; x += 2) {
        for (int y = -8; y <= 8; y += 2) {
            Sphere* s = new Sphere(Point3D((float)x, (float)y, 0.f), 1.f);
            s->set_material(new Cosine(((float)x + 8.f) / 16.f, 0.f, ((float)y + 8.f) / 16.f));
            add_geometry(s);
        }
    }
}
