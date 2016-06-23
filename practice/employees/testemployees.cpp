#include<iostream>
#include<string>
#include"Employee.h"
using namespace secret;

int main(){
  Employee first;
  first.addLastName("Belonenko");
  first.addFirstName("Vadim");
  first.display();
  return 0;

}
