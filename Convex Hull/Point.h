#include <iostream>
#include <string>

class Point{
private:
  int x;
  int y;

public:
  int getX(){return x;}
  int getY(){return y;}
  void setX(int x){this -> x = x;}
  void setY(int y){this -> y = y;}
  Point(int,int);
  std::string toString();
  bool operator <(const Point&);
  bool operator <=(const Point&);
  bool operator >(const Point&);
  bool operator >=(const Point&);
  bool operator ==(const Point&);
};
