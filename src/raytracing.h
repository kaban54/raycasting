#ifndef RAYTRACING_H
#define RAYTRACING_H

#include "vec.h"
#include "coordsys.h"
#include "shapes.h"
#include <SFML/Graphics.hpp>

class Camera {
    public:
    Vec pos;
    CoordSys screen_sys;

    explicit Camera (const Vec& pos_, const CoordSys& screen_sys_);

    Ray GetRay (int pix_x, int pix_y) const;
};

class Light {
    public:
    Vec pos;
    Vec col;

    explicit Light (const Vec& pos_, const Vec& col_ = Vec (1, 1, 1));
};


sf::Color GetsfColor (const Vec& col);

/*
class Scene {
    public:
    Camera cam;
    Light light;
};
*/

#endif