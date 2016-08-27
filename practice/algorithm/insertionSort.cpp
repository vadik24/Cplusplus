#include <iostream>
#include <fstream>
//insertion sort time complexity O(n^2)
//array[i...n] each pair(i,i+1) until i<n
//for loop each pair value swap if right value smaller than left value
// go back word until hit beginning of i
void insertSort(int array[],int length);
void printArray(int array[],int length);
int main(){

  std::ifstream myfile;
  myfile.open("array.txt");
  int array[100000];
  int value;
  int i=0;
  //collect values into array
  while(myfile>>value){
    array[i++]=value;
  }
  int length= sizeof(array)/sizeof(array[0]);
  //reference array
  insertSort(array,length);

  //print sort list of values
  printArray(array,length);
  return 0;
}
void insertSort(int array[], int length){
  for(int i=0;i<length-1;i++){
    if(array[i]>array[i+1]){
      int temp;
      temp = array[i];
      array[i] = array[i+1];
      array[i+1]=temp;
      int j=i;
      while(j>0){
        if(array[j-1]>array[j]){
          int temp;
          temp = array[j];
          array[j] = array[j-1];
          array[j-1]=temp;
          j--;
        }
        else{
          break;
        }
      }
    }
  }
}

void printArray(int array[],int length){
  for(int i=0;i<length;i++){
    std::cout << array[i] << " ";
  }
  std::cout<<std::endl;
}
