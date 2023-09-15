#include "coordsys.h"


CoordSys::CoordSys (double originX_, double originY_, double originZ_,
                    double  scaleX_, double  scaleY_, double  scaleZ_):
    origin (originX_, originY_, originZ_),
    scale  ( scaleX_,  scaleY_,  scaleZ_)
    {}

CoordSys::CoordSys (double originX_, double originY_, double originZ_, double scale_):
    origin (originX_, originY_, originZ_),
    scale (scale_, scale_, scale_)
    {}

CoordSys::CoordSys (const Vec& origin_, const Vec& scale_):
    origin (origin_),
    scale  (scale_)
    {}


void CoordSys::Move (double x, double y, double z) {
    origin.Move (x, y, z);
}

void CoordSys::Move (const Vec& vec) {
    origin = vec;
}

Vec CoordSys::GetRelCoords (const Vec& vec) const {
    Vec ret = vec - origin;
    ret.x /= scale.x;
    ret.y /= scale.y;
    ret.z /= scale.z;
    return ret;
}

Vec CoordSys::GetAbsCoords (const Vec& vec) const {
    return origin + (scale ^ vec);
}