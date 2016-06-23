#include<iostream>
#include<string>
#include<memory>
using namespace std;
int main(){
  int hi;
  hi = 235342;
  int *hello = new int(hi);
  shared_ptr<int> value(hello);
  cout<< *value;
  return 0;
}
