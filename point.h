#ifndef POINT_H_
#define POINT_H_

#include <iostream>

template<class T>
struct point {
  T x;
  T y;
};

template<class T>
point<T> operator+(const point<T>& A, const point<T>& B) {
    point<T> res;
    res.x = A.x + B.x;
    res.y = A.y + B.y;
    return res;
}

template<class T>
point<T> operator/=(point<T>& A, const double B) {
    A.x /= B;
    A.y /= B;
    return A;
}

template<class T>
std::istream& operator>> (std::istream& is, point<T>& p) {
  is >> p.x >> p.y;
  return is;
}

template<class T>
std::ostream& operator<< (std::ostream& os, const point<T>& p) {
  os << '[' << p.x << ' ' << p.y << ']';
  return os;
}

#endif
