#ifndef COORDSYS_H
#define COORDSYS_H

#include "vec.h"

class CoordSys {
    public:
    Vec origin;
    Vec scale;

    explicit CoordSys (double originX_, double originY_, double originZ_,
              double  scaleX_, double  scaleY_, double  scaleZ_);
    
    explicit CoordSys (double originX_ = 0, double originY_ = 0, double originZ_ = 0, double scale = 1);

    explicit CoordSys (const Vec& origin_ = Vec (0, 0, 0), const Vec& scale_ = Vec (1, 1, 1));

    void Move (double x, double y, double z);

    void Move (const Vec& vec);

    Vec GetRelCoords (const Vec& vec) const;

    Vec GetAbsCoords (const Vec& vec) const;
};

#endif