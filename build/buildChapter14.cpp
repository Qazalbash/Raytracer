/**
   This builds a scene that consists of 35 shaded spheres and a plane.
   Perspective viewing is used with a single sample per pixel.
   The spheres are the same as those in the Chapter 14 page one image.

   Courtesy Kevin Suffern.
*/

#include <tuple>

#include "../cameras/Parallel.hpp"
#include "../geometry/Plane.hpp"
#include "../geometry/Sphere.hpp"
#include "../materials/Cosine.hpp"
#include "../samplers/Simple.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Vector3D.hpp"
#include "../world/World.hpp"

const typedef std::tuple<Point3D, float, RGBColor> SphereData;

void World::build(void) {
    // view plane
    vplane.top_left.x     = -200.f;
    vplane.top_left.y     = 200.f;
    vplane.top_left.z     = 100.f;
    vplane.bottom_right.x = 200.f;
    vplane.bottom_right.y = -200.f;
    vplane.bottom_right.z = 100.f;
    vplane.hres           = 400;
    vplane.vres           = 400;

    bg_color = black;  // background color.

    // camera and sampler.
    set_camera(new Parallel(0.f, 0.f, -1.f));
    sampler_ptr = new Simple(camera_ptr, &vplane);

    // spheres
    const SphereData spheres[] = {SphereData(Point3D(5.f, 3.f, 0.f), 30.f, yellow),
                                  SphereData(Point3D(45.f, -7.f, -60.f), 20.f, brown),
                                  SphereData(Point3D(40.f, 43.f, -100.f), 17.f, darkGreen),
                                  SphereData(Point3D(-20.f, 28.f, -15.f), 20.f, orange),
                                  SphereData(Point3D(-25.f, -7.f, -35.f), 27.f, green),
                                  SphereData(Point3D(20.f, -27.f, -35.f), 25.f, lightGreen),
                                  SphereData(Point3D(35.f, 18.f, -35.f), 22.f, green),
                                  SphereData(Point3D(-57.f, -17.f, -50.f), 15.f, brown),
                                  SphereData(Point3D(-47.f, 16.f, -80.f), 23.f, lightGreen),
                                  SphereData(Point3D(-15.f, -32.f, -60.f), 22.f, darkGreen),
                                  SphereData(Point3D(-35.f, -37.f, -80.f), 22.f, darkYellow),
                                  SphereData(Point3D(10.f, 43.f, -80.f), 22.f, darkYellow),
                                  SphereData(Point3D(30.f, -7.f, -80.f), 10.f, darkYellow),
                                  SphereData(Point3D(-40.f, 48.f, -110.f), 18.f, darkGreen),
                                  SphereData(Point3D(-10.f, 53.f, -120.f), 18.f, brown),
                                  SphereData(Point3D(-55.f, -52.f, -100.f), 10.f, lightPurple),
                                  SphereData(Point3D(5.f, -52.f, -100.f), 15.f, brown),
                                  SphereData(Point3D(-20.f, -57.f, -120.f), 15.f, darkPurple),
                                  SphereData(Point3D(55.f, -27.f, -100.f), 17.f, darkGreen),
                                  SphereData(Point3D(50.f, -47.f, -120.f), 15.f, brown),
                                  SphereData(Point3D(70.f, -42.f, -150.f), 10.f, lightPurple),
                                  SphereData(Point3D(5.f, 73.f, -130.f), 12.f, lightPurple),
                                  SphereData(Point3D(66.f, 21.f, -130.f), 13.f, darkPurple),
                                  SphereData(Point3D(72.f, -12.f, -140.f), 12.f, lightPurple),
                                  SphereData(Point3D(64.f, 5.f, -160.f), 11.f, green),
                                  SphereData(Point3D(55.f, 38.f, -160.f), 12.f, lightPurple),
                                  SphereData(Point3D(-73.f, -2.f, -160.f), 12.f, lightPurple),
                                  SphereData(Point3D(30.f, -62.f, -140.f), 15.f, darkPurple),
                                  SphereData(Point3D(25.f, 63.f, -140.f), 15.f, darkPurple),
                                  SphereData(Point3D(-60.f, 46.f, -140.f), 15.f, darkPurple),
                                  SphereData(Point3D(-30.f, 68.f, -130.f), 12.f, lightPurple),
                                  SphereData(Point3D(58.f, 56.f, -180.f), 11.f, green),
                                  SphereData(Point3D(-63.f, -39.f, -180.f), 11.f, green),
                                  SphereData(Point3D(46.f, 68.f, -200.f), 10.f, lightPurple),
                                  SphereData(Point3D(-3.f, -72.f, -130.f), 12.f, lightPurple)};

    for (auto& sphere : spheres) {
        Sphere* sphere_ptr = new Sphere(std::get<0>(sphere), std::get<1>(sphere));
        sphere_ptr->set_material(new Cosine(std::get<2>(sphere)));
        add_geometry(sphere_ptr);
    }

    // vertical plane
    Plane* plane_ptr = new Plane(Point3D(0.f, 0.f, -150.f), Vector3D(0.0, 0.0, 1.0));
    plane_ptr->set_material(new Cosine(grey));
    add_geometry(plane_ptr);
}
