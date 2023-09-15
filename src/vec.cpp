#include "vec.h"

Vec::Vec (double x_, double y_, double z_): 
    x (x_),
    y (y_),
    z (z_)
    {}

void Vec::Move (double x_, double y_, double z_) {
    x = x_;
    y = y_;
    z = z_;
}

Vec Vec::operator-() const {
    return Vec (-x, -y, -z);
}

Vec operator+ (const Vec& vec1, const Vec& vec2) {
    return Vec (vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z);
}

Vec operator- (const Vec& vec1, const Vec& vec2) {
    return Vec (vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
}

Vec operator* (const Vec& vec, const double scalar) {
    return Vec (vec.x * scalar, vec.y * scalar, vec.z * scalar);
}

Vec operator* (const double scalar, const Vec& vec) {
    return vec * scalar;
}

Vec operator/ (const Vec& vec, const double scalar) {
    return Vec (vec.x / scalar, vec.y / scalar, vec.z / scalar);
}

Vec operator+= (Vec& vec1, const Vec& vec2) {
    vec1.x += vec2.x;
    vec1.y += vec2.y;
    vec1.z += vec2.z;
    return vec1;
}

Vec operator-= (Vec& vec1, const Vec& vec2) {
    vec1.x -= vec2.x;
    vec1.y -= vec2.y;
    vec1.z -= vec2.z;
    return vec1;
}

Vec operator*= (Vec& vec, const double scalar) {
    vec.x *= scalar;
    vec.y *= scalar;
    vec.z *= scalar;
    return vec;
}

Vec operator/= (Vec& vec, const double scalar) {
    vec.x /= scalar;
    vec.y /= scalar;
    vec.z /= scalar;
    return vec;
}

double operator, (const Vec& vec1, const Vec& vec2) {
    return vec1.x * vec2.x + vec2.y * vec2.y + vec1.z * vec2.z;
}

Vec operator^ (const Vec& vec1, const Vec& vec2) {
    return Vec (vec1.x * vec2.x, vec1.y * vec2.y, vec1.z * vec2.z);
}

double Vec::GetLen() const {
    return std::sqrt (x * x + y * y);
}

void Vec::Normalize () {
    *this /= GetLen ();
}

Vec Vec::operator! () const {
    Vec ret = *this;
    ret.Normalize();
    return ret;
}

Vec operator* (const Vec& vec1, const Vec& vec2) {
    return Vec (vec1.y * vec2.z - vec1.z * vec2.y,
                vec1.z * vec2.x - vec1.x * vec2.z,
                vec1.x * vec2.y - vec1.y * vec2.x);
}