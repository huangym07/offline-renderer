#ifndef __VEC_H__
#define __VEC_H__

#include <iostream>
#include <cmath>

template<class T> 
class Vec3 {
  public:
    // data member
    T e_[3];

    // constructor
    Vec3() : e_{} {}
    Vec3(T v) : e_{v, v, v} {}
    Vec3(T v1, T v2, T v3) : e_{v1, v2, v3} {}

    // member access
    T x() const { return e_[0]; }
    T y() const { return e_[1]; }
    T z() const { return e_[2]; }

    // index access
    T operator[] (int index) const { return e_[index]; }
    T& operator[] (int index) { return e_[index]; }

    // negative
    Vec3<T> operator- () { return Vec3<T>(-e_[0], -e_[1], -e_[2]); }

    // length
    double Length() const { return sqrt(LengthSquared()); }
    // length_squared
    double LengthSquared() const { return e_[0] * e_[0] + e_[1] * e_[1] + e_[2] * e_[2]; }
};

// Point3: an alias for Vec3
template<class T> using Point3 = Vec3<T>;

// <<
template<class T>
std::ostream& operator<< (std::ostream& out, const Vec3<T>& v) {
    out << v.e_[0] << ' ' << v.e_[1] << ' ' << v.e_[2];
    return out;
}

// +
template<class T> 
Vec3<T> operator+ (const Vec3<T>& v1, const Vec3<T>& v2) {
    return Vec3<T>(v1.e_[0] + v2.e_[0], v1.e_[1] + v2.e_[1], v1.e_[2] + v2.e_[2]);
}

// -
template<class T>
Vec3<T> operator- (const Vec3<T>& v1, const Vec3<T>& v2) {
    return Vec3<T>(v1.e_[0] - v2.e_[0], v1.e_[1] - v2.e_[1], v1.e_[2] - v2.e_[2]);
}

// * * *
template<class T>
Vec3<T> operator* (const Vec3<T>& v1, const Vec3<T>& v2) {
    return Vec3<T>(v1.e_[0] * v2.e_[0], v1.e_[1] * v2.e_[1], v1.e_[2] * v2.e_[2]);
}
template<class T>
Vec3<T> operator* (const Vec3<T>& v, double t) {
    return Vec3<T>(v.e_[0] * t, v.e_[1] * t, v.e_[2] * t);
}
template<class T>
Vec3<T> operator* (double t, const Vec3<T>& v) {
    return Vec3<T>(v.e_[0] * t, v.e_[1] * t, v.e_[2] * t);
}

// /
template<class T>
Vec3<T> operator/ (const Vec3<T>& v, double t) {
    return v * (1 / t);
}

// dot
template<class T>
Vec3<T> Dot(const Vec3<T>& v1, const Vec3<T>& v2) {
    return v1.e_[0] * v2.e_[0] + v1.e_[1] * v2.e_[1] + v1.e_[2] * v2.e_[2];
}

// cross
template<class T>
Vec3<T> Cross(const Vec3<T>& v1, const Vec3<T>& v2) {
    return Vec3<T>( v1.e_[1] * v2.e_[2] - v1.e_[2] * v2.e_[1],
                    v1.e_[2] * v2.e_[0] - v1.e_[0] * v2.e_[2],
                    v1.e_[0] * v2.e_[1] - v1.e_[1] * v2.e_[0] );
}

// unit vector
template<class T>
Vec3<T> UnitVector(const Vec3<T>& v) {
    return v / v.Length();
}

#endif // __VEC_H__
