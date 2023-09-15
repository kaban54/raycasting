#ifndef COORDSYS_H
#define COORDSYS_H

#include "vec.h"

class CoordSys {
    public:
    Vec origin;
    Vec scale;

    explicit CoordSys (double originX_ = 0, double originY_ = 0, double originZ_ = 0,
              double  scaleX_ = 1, double  scaleY_ = 1, double  scaleZ_ = 1);
    
    explicit CoordSys (double originX_ = 0, double originY_ = 0, double originZ_ = 0, double scale = 1);

    explicit CoordSys (const Vec& origin_ = Vec (0, 0, 0), const Vec& scale_ = Vec (1, 1, 1));

    void Move (double x, double y, double z);

    void Move (const Vec& vec);

    Vec GetRelCoords (const Vec& vec) const;

    Vec GetAbsCoords (const Vec& vec) const;
};

#endif