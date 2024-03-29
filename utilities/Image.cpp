#include "Image.hpp"

/**
 * @brief Construct a new Image:: Image object
 *
 * @param h
 * @param v
 */
Image::Image(const size_t h, const size_t v) {
    // Assign hres and vrex from parameters
    this->hres = h;
    this->vres = v;

    // Assign color pointer arrary
    this->colors = new RGBColor*[v];
    // Assign color arrary
    for (size_t i = 0UL; i < v;) colors[i++] = new RGBColor[h];
}

/**
 * @brief Construct a new Image:: Image object
 *
 * @param vp
 */
Image::Image(const ViewPlane& vp) {
    // Assign hres and vrex from Viewplane
    this->hres = vp.get_hres();
    this->vres = vp.get_vres();

    // Assign color pointer arrary
    this->colors = new RGBColor*[this->vres];
    // Assign color arrary
    for (size_t i = 0UL; i < (this->vres);) colors[i++] = new RGBColor[this->hres];
}

/**
 * @brief Destroy the Image:: Image object
 *
 */
Image::~Image() {
    // Delete pointers of each RGBcolor array
    for (size_t i = 0UL; i < this->vres; i++) delete[] this->colors[i];
    // Delete color**
    delete[] this->colors;
}

/**
 * @brief Set the pixel object at x,y to color
 *
 * @param x
 * @param y
 * @param color
 */
void Image::set_pixel(const size_t x, const size_t y, const RGBColor& color) { this->colors[x][y] = color; }

/**
 * @brief Set the pixel object at x,y to color
 *
 * @param x
 * @param y
 * @param color
 * @param samples
 */
void Image::set_pixel(const size_t x, const size_t y, const RGBColor& color, const int samples) {
    this->colors[x][y] = color / samples;
}

/**
 * @brief Write the image to a ppm file
 *
 * @param path
 */
void Image::write_ppm(const std::string path) const {
    float  maxRGB = 0.f, temp;
    size_t i = 0UL, j = 0UL;

    for (; i < this->vres; i++) {
        for (j = 0; j < this->hres; j++) {
            // Find largest value in all the r,g,b values in the color array.
            temp = max_element(colors[i][j].r, colors[i][j].g, colors[i][j].b);
            if (temp > maxRGB) maxRGB = temp;
        }
    }
    // Find scale using maxRGB
    const double scale = (maxRGB > 0.f) ? 225.0 / maxRGB : 1.0;

    std::ofstream file(path);

    file << "P3\n";
    file << this->hres << " " << this->vres << "\n";
    file << "225\n";

    for (i = 0UL; i < this->vres; i++) {
        for (j = 0UL; j < this->hres; j++) {
            // Write scaled r,g,b data to ppm file.
            file << std::to_string(int(colors[j][i].r * scale)) << " " << std::to_string(int(colors[j][i].g * scale))
                 << " " << std::to_string(int(colors[j][i].b * scale)) << " ";
        }
        file << "\n";
    }
    file.close();
}
