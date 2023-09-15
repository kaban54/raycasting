#include "shapes.h"

Sphere::Sphere (const Vec& center_, double radius_):
    center (center_),
    radius (radius_)
    {}

Sphere::Sphere (double x, double y, double z, double radius_):
    center (x, y, z),
    radius (radius_)
    {}

bool Sphere::Collides (const Ray& ray, Vec& col_pnt) {
    if (Distance (ray, center) > radius) return false;

    double a = (ray.dir, ray.dir);
    double b = (ray.dir, ray.start - center);
    double c = (ray.start - center, ray.start - center) - radius * radius;

    double D = std::sqrt(b * b - a * c) / a;

    double t = -b / a - D;

    if (t >= 0) {
        col_pnt = ray.start + t * ray.dir;
        return true;
    }

    t += D * 2;
    if (t < 0) return false;
    
    col_pnt = ray.start + t * ray.dir;
    return true;
}