#include<iostream>
using namespace std;
int main(){
  int x = 4;
  int y = 5;
  int&ref1 = x;
  int& ref2  = y;
  int const* hmm = new int[6];
  hmm = & y;
  cout << hmm[3];
  return 0;
}
