#include "raytracing.h"

Camera::Camera (const Vec& pos_, const CoordSys& screen_sys_):
    pos (pos_),
    screen_sys (screen_sys_)
    {}

Ray Camera::GetRay (int pix_x, int pix_y) const {
    Vec dx (screen_sys.scale.x, 0, 0);
    Vec dy (0, screen_sys.scale.y, 0);
    return Ray (pos, screen_sys.origin + dx * pix_x + dy * pix_y - pos);
}

Light::Light (const Vec& pos_, const Vec& col_):
    pos (pos_),
    col (col_)
    {}

sf::Color GetsfColor (const Vec& col) {
    Vec cpy = col * 255;

    if (cpy.x > 255) cpy.x = 255;
    if (cpy.y > 255) cpy.y = 255;
    if (cpy.z > 255) cpy.z = 255;

    return sf::Color (cpy.x, cpy.y, cpy.z);
}