#ifndef POINTSET_H
#define POINTSET_H

#include <vector>
#include "Point.cpp"


class PointSet{
private:
  int size;
  Point * min;
  std::vector<Point> set;
  //void merge(std::vector<Point>*,int, int, int, int);
  //void mergeSort(std::vector<Point>*,int, int);
  
 public:
  
  PointSet(int, int, int);
  PointSet(int);
  std::string toString();
  void pointSort();
  std::vector<Point>* getConvexHull(std::vector<Point>*);
  std::vector<Point>* getPoints(){
    return & (this -> set);
  }
  int getSize(){
    return this -> size;
  }
  Point getMin(){
    return *(this -> min);
  }
  //  ~PointSet();
};

#endif
