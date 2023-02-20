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
        // View plane
        vplane.top_left.x     = -10.0f;
        vplane.top_left.y     = 10.0f;
        vplane.top_left.z     = 10.0f;
        vplane.bottom_right.x = 10.0f;
        vplane.bottom_right.y = -10.0f;
        vplane.bottom_right.z = 10.0f;
        vplane.hres           = 400;
        vplane.vres           = 400;

        // Background color.
        bg_color = grey;

        // Camera and sampler.
        set_camera(new Parallel(0.0f, 0.0f, -1.0f));
        sampler_ptr = new Anti_Alias_Sampler(camera_ptr, &vplane);

        for (int x = -8; x <= 8; x += 2) {
                for (int y = -8; y <= 8; y += 2) {
                        Sphere* s = new Sphere(Point3D((float)x, (float)y, 0.0f), 1.0f);
                        s->set_material(new Cosine(((float)x + 8.0f) / 16.0f, 0.0f,
                                                   ((float)y + 8.0f) / 16.0f));
                        add_geometry(s);
                }
        }
}
