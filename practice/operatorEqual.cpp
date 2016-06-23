#include<iostream>
/*
* operator= called when object assigned to another object
* copy constructor != assigned
*/

class Object{
  public:
    Object operator=(Object& rightSide){
    //this point object left of equal sign
    std::cout << "Both object's equal match?"<<std::endl;
    if(this == &rightSide){
      std::cout << "Yes"<<std::endl;
    //*this is the object of left
      return(*this);

    }
    std::cout << "Nope"<<std::endl;
    return rightSide;
  }

};

int main(){
  Object first;
  Object second;
  //third is assigned to first, no operator=
  Object third = first;
  //copied constructor
  first = second;
  first = first;


  return 0;
}
