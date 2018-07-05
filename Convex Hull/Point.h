#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <string>

class Point{
 private:
  int x;
  int y;
  double angle;
  
 public:
  int getX(){return x;}
  int getY(){return y;}
  double getA(){return angle;}
  
  void setX(int x){this -> x = x;}
  void setY(int y){this -> y = y;}
  void setA(double a){this -> angle = a;}
  
  Point(int,int);
  std::string toString();
  
  bool operator <(const Point&);
  bool operator <=(const Point&);
  bool operator >(const Point&);
  bool operator >=(const Point&);
  bool operator ==(const Point&);
};
#endif
