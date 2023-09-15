#ifndef SHAPES_H
#define SHAPES_H

#include "vec.h"

class Shape {
    public:
    virtual bool Collides (const Ray& ray, Vec& col_pnt) = 0;
};

class Sphere : public Shape {
    public:
    Vec center;
    double radius;

    Sphere (const Vec& center_, double radius_);

    Sphere (double x, double y, double z, double radius_);

    bool Collides (const Ray& ray, Vec& col_pnt);
};

#endif