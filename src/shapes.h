#ifndef SHAPES_H
#define SHAPES_H

#include "vec.h"

class Shape {
    public:

    Vec color;

    explicit Shape ();

    explicit Shape (const Vec& color_);

    virtual bool Collides (const Ray& ray, Vec& col_pnt) const = 0;
    virtual Vec GetNormal (const Vec& point) const = 0;
};

class Sphere : public Shape {
    public:
    Vec center;
    double radius;

    explicit Sphere (const Vec& center_, double radius_, const Vec& color_ = Vec (1, 1, 1));

    explicit Sphere (double x, double y, double z, double radius_, const Vec& color_ = Vec (1, 1, 1));

    bool Collides (const Ray& ray, Vec& col_pnt) const;

    Vec GetNormal (const Vec& point) const;
};

#endif