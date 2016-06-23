#include <iostream>
using namespace std;
class Singleton{

private:
   static int mutables;
   static Singleton* single;
   Singleton(){};
   void operator=(const Singleton& rhs) = delete;
   Singleton(const Singleton& rhs) = delete;
public:
  static Singleton& getSingleton();
  void getMessage();
};
 void Singleton::getMessage(){
  cout << "One instance of class" << endl;
}
int mutables = 0;
Singleton* single = nullptr;
Singleton& Singleton::getSingleton(){

    single =  new Singleton();

  return *single;
}

int main(){
  Singleton& sinT = Singleton::getSingleton();
  sinT.getMessage();
}
