
/**
  This builds a simple scene that consists of a sphere, a triangle, and a
  plane.
  Parallel viewing is used with a single sample per pixel.
*/

#include "../cameras/Perspective.hpp"
#include "../geometry/Plane.hpp"
#include "../geometry/Sphere.hpp"
#include "../geometry/Triangle.hpp"
#include "../materials/Cosine.hpp"
#include "../samplers/Simple.hpp"
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
    sampler_ptr = new Simple(camera_ptr, &vplane);

    // sphere
    Sphere* sphere_ptr = new Sphere(Point3D(-3.f, 2.f, 0.f), 5.f);
    sphere_ptr->set_material(new Cosine(red));
    add_geometry(sphere_ptr);

    // triangle
    Point3D   a(2.5f, -5.f, 1.f);
    Point3D   b(14.f, -1.f, 0.f);
    Point3D   c(8.5f, 5.f, 0.5f);
    Triangle* triangle_ptr = new Triangle(a, b, c);
    triangle_ptr->set_material(new Cosine(blue));
    add_geometry(triangle_ptr);

    // plane
    Plane* plane_ptr = new Plane(Point3D(0.f, 1.f, 0.f), Vector3D(0.0, 10.0, 2.0));
    plane_ptr->set_material(new Cosine(green));  // green
    add_geometry(plane_ptr);
}
