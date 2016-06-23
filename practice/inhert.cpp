#include <iostream>

class Wood{
public:
  void prints(int i){}
  void prints(){
    std::cout << "super" << std::endl;
  }
  int hello = 4;
};
//paper: public Wood(parameter works)
class Paper: public Wood{
public:
  using Wood:: prints;
  void prints(){
    hello = 3;
    std::cout << "sub" << std::endl;
  }
};


int main(){
  Paper pap;
  pap.prints();
  std::cout << pap.hello;
}


//when upcasting, use pointer or reference to cast(static or dynamic)
//downcast use dynamic
