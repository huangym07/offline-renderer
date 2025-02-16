#ifndef __VEC_H__
#define __VEC_H__

#include <iostream>
#include <cmath>

template<size_t N, class T> class Vec;

template<size_t N, class T> 
class Vec {
  public:
    T e_[N];

    Vec() : e_{} {}
    template<class... Args>
    Vec(Args... values) : e_{values...} {}
    Vec(const Vec<N, T>& vec) { for (int i = 0; i < N; i++)  e_[i] = vec[i]; }

    Vec<N, T>& operator= (const Vec<N, T>& vec) { for (int i = 0; i < N; i++) e_[i] = vec[i];  return *this; }

    T operator[] (int index) const { static_assert(N > 0, "Vec<N, T> should fulfill N > 0 to call operator[]"); return e_[index]; }
    T& operator[] (int index) { static_assert(N > 0, "Vec<N, T> should fulfill N > 0 to call operator[]"); return e_[index]; }

    T x() { static_assert(N >= 1, "Vec<N, T> should fulfill N >= 1 to call x()"); return e_[0]; };
    T y() { static_assert(N >= 2, "Vec<N, T> should fulfill N >= 2 to call y()"); return e_[1]; };
    T z() { static_assert(N >= 3, "Vec<N, T> should fulfill N >= 3 to call z()"); return e_[2]; };
    T w() { static_assert(N >= 4, "Vec<N, T> should fulfill N >= 4 to call w()"); return e_[3]; };

    Vec<N, T> operator- () const { 
        Vec<N, T> vec;

        for (int i = 0; i < N; i++) vec[i] = -e_[i];

        return vec;
    }

    double Length() const { return sqrt(LengthSquared()); }
    double LengthSquared() const { 
        double res = 0.0;

        for (int i = 0; i < N; i++) res += e_[i] * e_[i];

        return res;
    }
};

template<size_t N, class T>
std::ostream& operator<< (std::ostream& out, const Vec<N, T>& vec) {
    for (int i = 0; i < N; i++) {
        out << vec.e_[i] << ' ';
    }
    return out;
}

template<size_t N, class T>
Vec<N, T> operator+ (const Vec<N, T>& vec1, const Vec<N, T>& vec2) {
    Vec<N, T> ret_vec;

    for (int i = 0; i < N; i++) ret_vec[i] = vec1[i] + vec2[i];

    return ret_vec;
}

template<size_t N, class T>
Vec<N, T> operator- (const Vec<N, T>& vec1, const Vec<N, T>& vec2) {
    Vec<N, T> ret_vec;

    for (int i = 0; i < N; i++) ret_vec[i] = vec1[i] - vec2[i];

    return ret_vec;
}

template<size_t N, class T>
Vec<N, T> operator* (const Vec<N, T>& vec1, const Vec<N, T>& vec2) {
    Vec<N, T> ret_vec;

    for (int i = 0; i < N; i++) ret_vec[i] = vec1[i] * vec2[i];

    return ret_vec;
}

template<size_t N, class T>
Vec<N, T> operator* (const Vec<N, T>& vec, double t) {
    Vec<N, T> ret_vec;

    for (int i = 0; i < N; i++) ret_vec[i] = vec[i] * t;

    return ret_vec;
}

template<size_t N, class T>
Vec<N, T> operator* (double t, const Vec<N, T>& vec) {
    Vec<N, T> ret_vec;

    for (int i = 0; i < N; i++) ret_vec[i] = vec[i] * t;

    return ret_vec;
}

template<size_t N, class T>
Vec<N, T> operator/ (const Vec<N, T>& vec, double t) {
    return (1 / t) * vec;
}

template<size_t N, class T>
double Dot (const Vec<N, T>& vec1, const Vec<N, T>& vec2) {
    double res = 0; 

    for (int i = 0; i < N; i++) res += vec1[i] * vec2[i];

    return res;
}

template<class T>
Vec<3, T> Cross (const Vec<3, T>& vec1, const Vec<3, T>& vec2) {
    return Vec<3, T>(   vec1[1] * vec2[2] - vec1[2] * vec2[1],
                        vec1[2] * vec2[0] - vec1[0] * vec2[2],
                        vec1[0] * vec2[1] - vec1[1] * vec2[0]);
}

template<size_t N, class T>
Vec<N, T> UnitVector(const Vec<N, T>& vec) {
    static_assert(N > 0, "Vec<N, T> should fulfill N > 0 to call UnitVector()");
    return vec / vec.Length();
}

#endif // __VEC_H__
