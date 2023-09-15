#include "vec.h"

#ifndef RAY_H
#define RAY_H

class Ray {
    public:
    Vec start;
    Vec dir;

    explicit Ray (const Vec& start_, const Vec& dir_);
};

double Distance (Ray ray, Vec point);

#endif