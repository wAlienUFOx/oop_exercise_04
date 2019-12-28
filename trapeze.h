#ifndef TRAPEZE_H_
#define TRAPEZE_H_
#include <iostream>
#include <cmath>
#include "point.h"


template<class T>
struct trapeze {
  point<T> points[4];  
  trapeze(std::istream& is);
  double area() const;
  point<T> center() const;
  void print(std::ostream& os) const;
};

template<class T>
trapeze<T>::trapeze(std::istream& is) {
  for(int i = 0; i < 4; ++i){
    is >> points[i];
  }
  if((points[2].y - points[1].y) / (points[2].x - points[1].x) != (points[3].y - points[0].y) / (points[3].x - points[0].x))
      throw std::logic_error("It`s not a trapeze");
}

template<class T>
double trapeze<T>::area() const {
  
  return 0.5 * std::abs( points[0].x * points[1].y + points[1].x * points[2].y + points[2].x * points[3].y + points[3].x * points[0].y - points[1].x * points[0].y - points[2].x * points[1].y - points[3].x * points[2].y - points[0].x * points[3].y);
}

template<class T>
point<T> trapeze<T>::center() const {
  point<T> res;
  res.x = (points[0].x + points[1].x + points[2].x + points[3].x) / 4;
  res.y = (points[0].y + points[1].y + points[2].y + points[3].y) / 4;
  return res;

}

template<class T>
void trapeze<T>::print(std::ostream& os) const {
  for(int i = 0; i < 4; ++i){
    os << points[i];
    if(i + 1 != 4){
      os << ' ';
    }
  }
}

#endif 
