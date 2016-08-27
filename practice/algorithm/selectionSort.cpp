#include <iostream>
#include <fstream>

//Selection sort algorithm
//array[i,n-1]
//for each element in array, set min value of array
//for each element in array, find lowest value
void selectionSort(int array[],int length);
void printArray(int array[],int length);
int main(){
  std::ifstream myfile;
  myfile.open("array.txt");
  int value;
  int array[100000];
  int length=sizeof(array)/sizeof(array[0]);
  int i=0;
  while(myfile>>value){
    array[i++] = value;
  }
  selectionSort(array,length);
  printArray(array,length);
  return 0;
}

void selectionSort(int array[],int length){
  for(int i=0;i<length-1;i++){
    //minValue = element in array with lowest value
    int minValue=i;
    for(int j=i+1;j<length;j++){
      if(array[minValue]>array[j]){
        minValue = j;
      }
    }
    int temp = array[i];
    array[i] = array[minValue];
    array[minValue] = temp;
  }
}
void printArray(int array[],int length){
  for(int i=0;i<length;i++){
    std::cout << array[i] << " ";
  }
  std::cout<<std::endl;
}
