#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

/**
    This file caches common values and constants.

    Courtesy Kevin Suffern.
*/

#include <cstdlib>

#include "RGBColor.hpp"

const float PI        = 3.1415926535897932384f;
const float TWO_PI    = 6.2831853071795864769f;
const float PI_ON_180 = 0.0174532925199432957f;
const float invPI     = 0.3183098861837906715f;
const float invTWO_PI = 0.1591549430918953358f;

const float kEpsilon   = 0.0001f;
const float kHugeValue = 1.0E10f;

const RGBColor black       = {0.f};
const RGBColor white       = {1.f};
const RGBColor red         = {1.f, 0.f, 0.f};
const RGBColor green       = {0.f, 1.f, 0.f};
const RGBColor blue        = {0.f, 0.f, 1.f};
const RGBColor yellow      = {1.f, 1.f, 0.f};
const RGBColor brown       = {0.71f, 0.40f, 0.16f};
const RGBColor darkGreen   = {0.f, 0.41f, 0.41f};
const RGBColor orange      = {1.f, 0.75f, 0.f};
const RGBColor lightGreen  = {0.65f, 1.f, 0.30f};
const RGBColor darkYellow  = {0.61f, 0.61f, 0.f};
const RGBColor lightPurple = {0.65f, 0.3f, 1.f};
const RGBColor darkPurple  = {0.5f, 0.f, 1.f};
const RGBColor grey        = {0.25f};

const float invRAND_MAX = 1.f / (float)RAND_MAX;

#endif