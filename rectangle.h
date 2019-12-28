#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <iostream>
#include "point.h"
#include <cmath>

template<class T>
struct rectangle {
  point<T> points[4];
  rectangle(std::istream& is);
  double area() const;
  point<T> center() const;
  void print(std::ostream& os) const;
};

template<class T>
rectangle<T>::rectangle(std::istream& is) {
  for(int i = 0; i < 4; ++i){
    is >> points[i];
  }
  double a, b, c, d, d1, d2, ABC, BCD, CDA, DAB;
  a = sqrt((points[1].x - points[0].x) * (points[1].x - points[0].x) + (points[1].y - points[0].y) * (points[1].y - points[0].y));
  b = sqrt((points[2].x - points[1].x) * (points[2].x - points[1].x) + (points[2].y - points[1].y) * (points[2].y - points[1].y));
  c = sqrt((points[2].x - points[3].x) * (points[2].x - points[3].x) + (points[2].y - points[3].y) * (points[2].y - points[3].y));
  d = sqrt((points[3].x - points[0].x) * (points[3].x - points[0].x) + (points[3].y - points[0].y) * (points[3].y - points[0].y));
  d1 = sqrt((points[1].x - points[3].x) * (points[1].x - points[3].x) + (points[1].y - points[3].y) * (points[1].y - points[3].y));
  d2 = sqrt((points[2].x - points[0].x) * (points[2].x - points[0].x) + (points[2].y - points[0].y) * (points[2].y - points[0].y));
  ABC = (a * a + b * b - d2 * d2) / 2 * a * b;
  BCD = (b * b + c * c - d1 * d1) / 2 * b * c;
  CDA = (d * d + c * c - d2 * d2) / 2 * d * c;
  DAB = (a * a + d * d - d1 * d1) / 2 * a * d;
  if(ABC != BCD || ABC != CDA || ABC != DAB)
    throw std::logic_error("It`s not a rectangle");
}

template<class T>
double rectangle<T>::area() const {
  const T a =  sqrt((points[1].x - points[0].x) * (points[1].x - points[0].x) + (points[1].y - points[0].y) * (points[1].y - points[0].y));
  const T b =  sqrt((points[2].x - points[1].x) * (points[2].x - points[1].x) + (points[2].y - points[1].y) * (points[2].y - points[1].y));
  return a * b;
}

template<class T>
point<T> rectangle<T>::center() const {
  point<T> res;
  res.x = (points[0].x + points[1].x + points[2].x + points[3].x) / 4;
  res.y = (points[0].y + points[1].y + points[2].y + points[3].y) / 4;
  return res;
}

template<class T>
void rectangle<T>::print(std::ostream& os) const {
  for(int i = 0; i < 4; ++i){
      os << points[i];
    if(i + 1 != 4){
      os << ' ';
    }
  }
}

#endif 
