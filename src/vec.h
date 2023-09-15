#ifndef VEC_H
#define VEC_H

#include <cmath>

class Vec {
    public:
    double x;
    double y;
    double z;

    explicit Vec (double x_, double y_, double z_);

    void Move (double x_, double y_, double z_);

    Vec operator-() const;

    double GetLen() const;

    void Normalize();

    Vec operator!() const;
};

Vec operator+ (const Vec& vec1, const Vec& vec2);

Vec operator- (const Vec& vec1, const Vec& vec2);

Vec operator* (const Vec& vec, const double scalar);

Vec operator* (const double scalar, const Vec& vec);

Vec operator/ (const Vec& vec, const double scalar);

Vec operator+= (Vec& vec1, const Vec& vec2);

Vec operator-= (Vec& vec1, const Vec& vec2);

Vec operator*= (Vec& vec, const double scalar);

Vec operator/= (Vec& vec, const double scalar);

double operator, (const Vec& vec1, const Vec& vec2);

Vec operator^ (const Vec& vec1, const Vec& vec2);


#endif