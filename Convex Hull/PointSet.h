#include <vector>
#include "Point.cpp"


class PointSet{
private:
  int size;
  std::vector<Point> set;
  void merge(std::vector<Point>*,int, int, int, int);
public:
  PointSet(int, int, int);
  std::string toString();
  void mergeSort(std::vector<Point>*,int, int);
  std::vector<Point>* getPoints(){
    return & (this -> set);
  }
  int getSize(){
    return this -> size;
  }
  //  ~PointSet();
};
