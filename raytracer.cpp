#include <iostream>

#include "materials/Cosine.hpp"
#include "samplers/Sampler.hpp"
#include "utilities/Image.hpp"
#include "utilities/RGBColor.hpp"
#include "utilities/Ray.hpp"
#include "utilities/ShadeInfo.hpp"
#include "world/ViewPlane.hpp"
#include "world/World.hpp"

int main(void) {
    World world;
    world.build();

    Sampler   *sampler   = world.sampler_ptr;
    ViewPlane &viewplane = world.vplane;

    Image            image(viewplane);
    std::vector<Ray> rays;
    RGBColor         pixel_color(0);

#pragma omp parallel for
    for (size_t x = 0; x < viewplane.hres; x++) {
        for (size_t y = 0; y < viewplane.vres; y++) {
            RGBColor pixel_color(0);

            std::vector<Ray> rays = sampler->get_rays(x, y);

            for (const auto &ray : rays) {
                const float weight = ray.w;
                ShadeInfo   sinfo  = world.hit_objects(ray);
                if (sinfo.hit)
                    pixel_color += weight * sinfo.material_ptr->shade(sinfo);
                else
                    pixel_color += weight * world.bg_color;
            }
            image.set_pixel(x, y, pixel_color, 100);
        }
    }

    image.write_ppm("scene.ppm");

    std::cout << "Wrote image.\n";

    return 0;
}
