#include "ray.h"

Ray::Ray (const Vec& start_, const Vec& dir_):
    start (start_),
    dir (dir_)
    {}

double Distance (Ray ray, Vec point) {
    return ((ray.start - point) * !(ray.dir)).GetLen();
}