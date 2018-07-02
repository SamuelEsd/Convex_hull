#include <ctime>
#include <typeinfo>
#include "PointSet.h"

using namespace std;

// Constructor for a set of points
PointSet::PointSet(int s, int xmax, int ymax){
  this -> size = s;
  srand(time(NULL));
  for(int i = 0; i < size; i++){
    int x = rand() % (xmax - 5) + 5;
    int y = rand() % (ymax - 5) + 5;
    Point p(x,y);
    set.insert(set.begin()+i,p);
  }
}

//
string PointSet::toString(){
  string o = "[";
  for(int i = 0; i < size; i++){
    o = o + set[i].toString();
  }
  o = o + "]\n";
  return o;
}

void printV(vector<Point>* v, int s, int f){
  cout << "[";
  for(int i = s; i <= f; i++){
    cout << ((*v).at(i)).toString();
  }
  cout << "]";
}

void merge(vector<Point>* v,int l1,int l2,int r1,int r2){
  vector<Point> temp;
  
  int a = 0;
  int b = 0;
  
  for(int i = 0; i < (r2-l1)+1; i++){
    if (b == (r2-r1)+1){
      temp.insert(temp.begin()+i,(*v).at(l1+a));
      a++;
    }
    else if (a == (l2-l1)+1) {
      temp.insert(temp.begin()+i,(*v).at(r1+b));
      b++;
    }
    else if ((*v).at(l1+a) < (*v).at(r1+b)){
      temp.insert(temp.begin()+i,(*v).at(l1+a));
      a++;
    }
    else if ((*v).at(r1+b) < (*v).at(l1+a)){
      temp.insert(temp.begin()+i,(*v).at(r1+b));
      b++;
    }
    else{
      temp.insert(temp.begin()+i,(*v).at(l1+a));
      a++;
    }
  }
  
  for(int i = 0; i < (r2-l1)+1; i++){
    (*v)[i+l1] = temp.at(i);
  }
  cout << "Merge de " << l1 << " a " << r2 << " : ";
  printV(v,l1,r2);
  cout << endl;
  cout << endl;
}

//
void mergeSort(vector<Point>* v ,int l, int r) {
  if ( r > l){
    int mid1 = (l+r)/2;
    int mid2 = ((l+r)/2)+1;
    cout << "mergeSort de " << l << " a "<< mid1 << endl;
    printV(v,l,mid1);
    cout << endl;
    mergeSort(v, l, mid1);
    
    cout << "mergeSort de " << mid2 << " a "<< r << endl;
    printV(v,mid2,r);
    cout << endl;
    mergeSort(v, mid2, r);

    cout << endl;
    cout << "merge de (" << l << ","<< mid1 << ") y ("<< mid2 << ","<< r << ")"<< endl;
    merge(v, l, mid1, mid2, r);
  }
}

// int main(){
//   Point hola(32,30);
//   Point hola1(32,30);
//   //  cout << hola.toString() << "\n";
//   //cout << to_string(hola == hola1) << "\n";

//   PointSet conj(5 , 100, 100);
//   cout << "Inicial : "<< conj.toString() << endl;
  
//   mergeSort(conj.getPoints(),0,conj.getSize()-1);

//   cout << conj.toString() << "\n";
//   return 0;
// }

