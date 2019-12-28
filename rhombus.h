#ifndef RHOMBUS_H_
#define RHOMBUS_H_
#include <iostream>
#include <cmath>
#include "point.h"


template<class T>
struct rhombus {
  point<T> points[4];  
  rhombus(std::istream& is);
  double area() const;
  point<T> center() const;
  void print(std::ostream& os) const;
};

template<class T>
rhombus<T>::rhombus(std::istream& is) {
  for(int i = 0; i < 4; ++i){
    is >> points[i];
  }
  double a, b, c, d;
  a = sqrt((points[1].x - points[0].x) * (points[1].x - points[0].x) + (points[1].y - points[0].y) * (points[1].y - points[0].y));
  b = sqrt((points[2].x - points[1].x) * (points[2].x - points[1].x) + (points[2].y - points[1].y) * (points[2].y - points[1].y));
  c = sqrt((points[2].x - points[3].x) * (points[2].x - points[3].x) + (points[2].y - points[3].y) * (points[2].y - points[3].y));
  d = sqrt((points[3].x - points[0].x) * (points[3].x - points[0].x) + (points[3].y - points[0].y) * (points[3].y - points[0].y));
  if(a != b || a != c || a != d)
      throw std::logic_error("It`s not a rhombus");
}

template<class T>
double rhombus<T>::area() const {
  const T d1 =  sqrt((points[0].x - points[2].x) * (points[0].x - points[2].x) + (points[0].y - points[2].y) * (points[0].y - points[2].y));
  const T d2 =  sqrt((points[1].x - points[3].x) * (points[1].x - points[3].x) + (points[1].y - points[3].y) * (points[1].y - points[3].y));
  return d1 * d2 / 2;
}

template<class T>
point<T> rhombus<T>::center() const {
  point<T> res;
  res.x = (points[0].x + points[1].x + points[2].x + points[3].x) / 4;
  res.y = (points[0].y + points[1].y + points[2].y + points[3].y) / 4;
  return res;
}

template<class T>
void rhombus<T>::print(std::ostream& os) const {
  for(int i = 0; i < 4; ++i){
      os << points[i];
    if(i + 1 != 4){
      os << ' ';
    }
  }
}

#endif 
