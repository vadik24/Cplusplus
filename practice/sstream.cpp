#include<sstream>
#include<string>
#include<iostream>
/*
* to transfer string to numbers
* use istringstream/ostringstream
*
*/
//methods
void  inputStream();
void  outputStream();

int main(){
  inputStream();
  outputStream();
  return 0;
}

void inputStream(){
  std::istringstream iss("any string or value");
  int value;
  iss >> value;
  //return 0 due to it's a string not value
  std::cout << value;
}

void outputStream(){
  std::ostringstream oss;
  oss << "Hello everyone";
  std::cout << oss.str();
}
