// multiply both value without using multiplcation
#include <iostream>
//positive values
int multiply(int x, int y){
  if(x==0){
    return 0;
  }
  return y + multiply(x-1,y);
}

// any value:positive or negative
int multiply2(int x, int y){
  if(y==0){
    return 0;
  }
  else if(y<0){
    return -multiply2(x,-y);
  }
  return x + multiply2(x,y-1);
}

//shortest way to create a function multi any values
int multiplyShort(int x, int y){
  return(int) x/(1/(float)y);
}

int main(){

  // positive values function
  std:: cout<< multiply(5,3)<< std::endl;

  // positive/negative values function
  std:: cout<< multiply2(5,-3)<< std::endl;


    // positive/negative values short function
    std:: cout<< multiplyShort(5,-3)<< std::endl;

  return 0;
}
