#include "ViewPlane.hpp"

/**
 * @brief Construct a new View Plane:: View Plane object
 *
 */
ViewPlane::ViewPlane() {
    top_left     = Point3D(-320.f, 240.f, 0.f);
    bottom_right = Point3D(top_left.x + hres, top_left.y + vres, 0.f);
    normal       = Vector3D(0.0, 0.0, -1.0);
    hres         = 640UL;
    vres         = 480UL;
}

/**
 * @brief Get the horizontal resolution
 *
 * @return int
 */
size_t ViewPlane::get_hres() const { return hres; }

/**
 * @brief Set the horizontal resolution
 *
 * @param hresVal
 */
void ViewPlane::set_hres(size_t hresVal) { hres = hresVal; }

/**
 * @brief Get the vertical resolution
 *
 * @return int
 */
size_t ViewPlane::get_vres() const { return vres; }

/**
 * @brief Set the vertical resolution
 *
 * @param vresVal
 */
void ViewPlane::set_vres(size_t vresVal) { vres = vresVal; }