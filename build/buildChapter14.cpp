/**
   This builds a scene that consists of 35 shaded spheres and a plane.
   Perspective viewing is used with a single sample per pixel.
   The spheres are the same as those in the Chapter 14 page one image.

   Courtesy Kevin Suffern.
*/

#include "../cameras/Parallel.hpp"
#include "../geometry/Plane.hpp"
#include "../geometry/Sphere.hpp"
#include "../materials/Cosine.hpp"
#include "../samplers/Simple.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Vector3D.hpp"
#include "../world/World.hpp"

void World::build(void) {
        // view plane
        vplane.top_left.x     = -200.0f;
        vplane.top_left.y     = 200.0f;
        vplane.top_left.z     = 100.0f;
        vplane.bottom_right.x = 200.0f;
        vplane.bottom_right.y = -200.0f;
        vplane.bottom_right.z = 100.0f;
        vplane.hres           = 400;
        vplane.vres           = 400;

        bg_color = black;  // background color.

        // camera and sampler.
        set_camera(new Parallel(0.0f, 0.0f, -1.0f));
        sampler_ptr = new Simple(camera_ptr, &vplane);

        // spheres
        Sphere* sphere_ptr1 = new Sphere(Point3D(5.0f, 3.0f, 0.0f), 30.0f);
        sphere_ptr1->set_material(new Cosine(yellow));  // yellow
        add_geometry(sphere_ptr1);

        Sphere* sphere_ptr2 = new Sphere(Point3D(45.0f, -7.0f, -60.0f), 20.0f);
        sphere_ptr2->set_material(new Cosine(brown));  // brown
        add_geometry(sphere_ptr2);

        Sphere* sphere_ptr3 = new Sphere(Point3D(40.0f, 43.0f, -100.0f), 17.0f);
        sphere_ptr3->set_material(new Cosine(darkGreen));  // dark green
        add_geometry(sphere_ptr3);

        Sphere* sphere_ptr4 = new Sphere(Point3D(-20.0f, 28.0f, -15.0f), 20.0f);
        sphere_ptr4->set_material(new Cosine(orange));  // orange
        add_geometry(sphere_ptr4);

        Sphere* sphere_ptr5 = new Sphere(Point3D(-25.0f, -7.0f, -35.0f), 27.0f);
        sphere_ptr5->set_material(new Cosine(green));  // green
        add_geometry(sphere_ptr5);

        Sphere* sphere_ptr6 = new Sphere(Point3D(20.0f, -27.0f, -35.0f), 25.0f);
        sphere_ptr6->set_material(new Cosine(lightGreen));  // light green
        add_geometry(sphere_ptr6);

        Sphere* sphere_ptr7 = new Sphere(Point3D(35.0f, 18.0f, -35.0f), 22.0f);
        sphere_ptr7->set_material(new Cosine(green));  // green
        add_geometry(sphere_ptr7);

        Sphere* sphere_ptr8 = new Sphere(Point3D(-57.0f, -17.0f, -50.0f), 15.0f);
        sphere_ptr8->set_material(new Cosine(brown));  // brown
        add_geometry(sphere_ptr8);

        Sphere* sphere_ptr9 = new Sphere(Point3D(-47.0f, 16.0f, -80.0f), 23.0f);
        sphere_ptr9->set_material(new Cosine(lightGreen));  // light green
        add_geometry(sphere_ptr9);

        Sphere* sphere_ptr10 = new Sphere(Point3D(-15.0f, -32.0f, -60.0f), 22.0f);
        sphere_ptr10->set_material(new Cosine(darkGreen));  // dark green
        add_geometry(sphere_ptr10);

        Sphere* sphere_ptr11 = new Sphere(Point3D(-35.0f, -37.0f, -80.0f), 22.0f);
        sphere_ptr11->set_material(new Cosine(darkYellow));  // dark yellow
        add_geometry(sphere_ptr11);

        Sphere* sphere_ptr12 = new Sphere(Point3D(10.0f, 43.0f, -80.0f), 22.0f);
        sphere_ptr12->set_material(new Cosine(darkYellow));  // dark yellow
        add_geometry(sphere_ptr12);

        Sphere* sphere_ptr13 = new Sphere(Point3D(30.0f, -7.0f, -80.0f), 10.0f);
        sphere_ptr13->set_material(new Cosine(darkYellow));  // dark yellow
        add_geometry(sphere_ptr13);

        Sphere* sphere_ptr14 = new Sphere(Point3D(-40.0f, 48.0f, -110.0f), 18.0f);
        sphere_ptr14->set_material(new Cosine(darkGreen));  // dark green
        add_geometry(sphere_ptr14);

        Sphere* sphere_ptr15 = new Sphere(Point3D(-10.0f, 53.0f, -120.0f), 18.0f);
        sphere_ptr15->set_material(new Cosine(brown));  // brown
        add_geometry(sphere_ptr15);

        Sphere* sphere_ptr16 = new Sphere(Point3D(-55.0f, -52.0f, -100.0f), 10.0f);
        sphere_ptr16->set_material(new Cosine(lightPurple));  // light purple
        add_geometry(sphere_ptr16);

        Sphere* sphere_ptr17 = new Sphere(Point3D(5.0f, -52.0f, -100.0f), 15.0f);
        sphere_ptr17->set_material(new Cosine(brown));  // browm
        add_geometry(sphere_ptr17);

        Sphere* sphere_ptr18 = new Sphere(Point3D(-20.0f, -57.0f, -120.0f), 15.0f);
        sphere_ptr18->set_material(new Cosine(darkPurple));  // dark purple
        add_geometry(sphere_ptr18);

        Sphere* sphere_ptr19 = new Sphere(Point3D(55.0f, -27.0f, -100.0f), 17.0f);
        sphere_ptr19->set_material(new Cosine(darkGreen));  // dark green
        add_geometry(sphere_ptr19);

        Sphere* sphere_ptr20 = new Sphere(Point3D(50.0f, -47.0f, -120.0f), 15.0f);
        sphere_ptr20->set_material(new Cosine(brown));  // browm
        add_geometry(sphere_ptr20);

        Sphere* sphere_ptr21 = new Sphere(Point3D(70.0f, -42.0f, -150.0f), 10.0f);
        sphere_ptr21->set_material(new Cosine(lightPurple));  // light purple
        add_geometry(sphere_ptr21);

        Sphere* sphere_ptr22 = new Sphere(Point3D(5.0f, 73.0f, -130.0f), 12.0f);
        sphere_ptr22->set_material(new Cosine(lightPurple));  // light purple
        add_geometry(sphere_ptr22);

        Sphere* sphere_ptr23 = new Sphere(Point3D(66.0f, 21.0f, -130.0f), 13.0f);
        sphere_ptr23->set_material(new Cosine(darkPurple));  // dark purple
        add_geometry(sphere_ptr23);

        Sphere* sphere_ptr24 = new Sphere(Point3D(72.0f, -12.0f, -140.0f), 12.0f);
        sphere_ptr24->set_material(new Cosine(lightPurple));  // light purple
        add_geometry(sphere_ptr24);

        Sphere* sphere_ptr25 = new Sphere(Point3D(64.0f, 5.0f, -160.0f), 11.0f);
        sphere_ptr25->set_material(new Cosine(green));  // green
        add_geometry(sphere_ptr25);

        Sphere* sphere_ptr26 = new Sphere(Point3D(55.0f, 38.0f, -160.0f), 12.0f);
        sphere_ptr26->set_material(new Cosine(lightPurple));  // light purple
        add_geometry(sphere_ptr26);

        Sphere* sphere_ptr27 = new Sphere(Point3D(-73.0f, -2.0f, -160.0f), 12.0f);
        sphere_ptr27->set_material(new Cosine(lightPurple));  // light purple
        add_geometry(sphere_ptr27);

        Sphere* sphere_ptr28 = new Sphere(Point3D(30.0f, -62.0f, -140.0f), 15.0f);
        sphere_ptr28->set_material(new Cosine(darkPurple));  // dark purple
        add_geometry(sphere_ptr28);

        Sphere* sphere_ptr29 = new Sphere(Point3D(25.0f, 63.0f, -140.0f), 15.0f);
        sphere_ptr29->set_material(new Cosine(darkPurple));  // dark purple
        add_geometry(sphere_ptr29);

        Sphere* sphere_ptr30 = new Sphere(Point3D(-60.0f, 46.0f, -140.0f), 15.0f);
        sphere_ptr30->set_material(new Cosine(darkPurple));  // dark purple
        add_geometry(sphere_ptr30);

        Sphere* sphere_ptr31 = new Sphere(Point3D(-30.0f, 68.0f, -130.0f), 12.0f);
        sphere_ptr31->set_material(new Cosine(lightPurple));  // light purple
        add_geometry(sphere_ptr31);

        Sphere* sphere_ptr32 = new Sphere(Point3D(58.0f, 56.0f, -180.0f), 11.0f);
        sphere_ptr32->set_material(new Cosine(green));  //  green
        add_geometry(sphere_ptr32);

        Sphere* sphere_ptr33 = new Sphere(Point3D(-63.0f, -39.0f, -180.0f), 11.0f);
        sphere_ptr33->set_material(new Cosine(green));  // green
        add_geometry(sphere_ptr33);

        Sphere* sphere_ptr34 = new Sphere(Point3D(46.0f, 68.0f, -200.0f), 10.0f);
        sphere_ptr34->set_material(new Cosine(lightPurple));  // light purple
        add_geometry(sphere_ptr34);

        Sphere* sphere_ptr35 = new Sphere(Point3D(-3.0f, -72.0f, -130.0f), 12.0f);
        sphere_ptr35->set_material(new Cosine(lightPurple));  // light purple
        add_geometry(sphere_ptr35);

        // vertical plane
        Plane* plane_ptr = new Plane(Point3D(0.0f, 0.0f, -150.0f), Vector3D(0.0, 0.0, 1.0));
        plane_ptr->set_material(new Cosine(grey));
        add_geometry(plane_ptr);
}
