
/**
  This builds a Anti_Alias_Sampler scene that consists of a sphere, a triangle,
  and a plane. Parallel viewing is used with a single sample per pixel.
*/

#include "../cameras/Perspective.hpp"
#include "../geometry/Plane.hpp"
#include "../geometry/Sphere.hpp"
#include "../geometry/Triangle.hpp"
#include "../materials/Cosine.hpp"
#include "../samplers/Anti_Alias_Sampler.hpp"
#include "../utilities/Constants.hpp"
#include "../world/World.hpp"

void World::build(void) {
    // View plane  .
    vplane.top_left.x     = -10.f;
    vplane.top_left.y     = 10.f;
    vplane.top_left.z     = 10.f;
    vplane.bottom_right.x = 10.f;
    vplane.bottom_right.y = -10.f;
    vplane.bottom_right.z = 10.f;
    vplane.hres           = 400;
    vplane.vres           = 400;

    // Background color.
    bg_color = black;

    // Camera and sampler.
    set_camera(new Perspective(0.f, 0.f, 20.f));
    sampler_ptr = new Anti_Alias_Sampler(camera_ptr, &vplane);

    // sphere
    Sphere* sphere_ptr = new Sphere(Point3D(-3.f, 2.f, 0.f), 5.f);
    sphere_ptr->set_material(new Cosine(red));
    add_geometry(sphere_ptr);

    // triangle
    Point3D   a(2.5, -5, 1);
    Point3D   b(14, -1, 0);
    Point3D   c(8.5, 5, 0.5);
    Triangle* triangle_ptr = new Triangle(a, b, c);
    triangle_ptr->set_material(new Cosine(blue));
    add_geometry(triangle_ptr);

    // plane
    Plane* plane_ptr = new Plane(Point3D(0.f, 1.f, 0.f), Vector3D(0.f, 10.f, 2.f));
    plane_ptr->set_material(new Cosine(green));  // green
    add_geometry(plane_ptr);
}
