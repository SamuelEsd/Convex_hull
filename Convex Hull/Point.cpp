#include "Point.h"

using namespace std;


Point::Point(int x, int y){
  this -> x = x;
  this -> y = y;
  this -> angle = 0.0;
}

string Point::toString(){
  return "("+ to_string(this->x) + ","+ to_string(this->y) +")  "+to_string(this->angle)+"\n";
}

  
bool Point::operator <(const Point& p){
  if (y < p.y)
    return true;
  if (y == p.y && x < p.x)
    return true;
  return false;
}
bool Point::operator <=(const Point& p){
  if (y < p.y || y == p.y)
    return true;
  if ((y == p.y && x < p.x) || (y == p.y && x == p.x))
    return true;
  return false;
}
bool Point::operator >(const Point& p){
  if (y > p.y)
    return true;
  if (y == p.y && x > p.x)
    return true;
  return false;
}
bool Point::operator >=(const Point& p){
  if (y > p.y || y == p.y)
    return true;
  if ((y == p.y && x > p.x) || (y == p.y && x == p.x))
    return true;
  return false;
}
bool Point::operator ==(const Point& p){
  if (y == p.y && x == p.x)
    return true;
  return false;
}

// int main (){
//   Point hola(1,2);
//   hola.setA(3.45);
//   cout << hola.toString();  
//   return 0;
// }
