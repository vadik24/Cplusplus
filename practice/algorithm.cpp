#include <iostream>
//create a merge sort algorithm
//divide array into subarray left & right
//conquer two leaf child
//combine two subarray into one
// divide/conquer is O(logN), Merge two array into one O(N) so O(nlogN)

void mergeSort(int *array,int l, int r);
void combine(int *array,int l,int m,int r);
int main(){
  int array[] = {7,4,3};
  int length = sizeof(array)/sizeof(array[0]);
  mergeSort(array,0,length-1);
  for(int i=0;i<length;i++){
    std::cout<< array[i]<<std::endl;
  }
  return 0;
}

//sort the array
//element l-left r-right of array
void mergeSort(int* array,int l,int r){
  //check if it leaf problem else do subproblem
  if(array == 0 || r-l==0){
    return;
  }
  int length = (r-l)/2;
  //left
  mergeSort(array,l,length);
  //right
  mergeSort(array,length+1,r);
  //hit end subproblem,conquer
  combine(array,l,length/2,r);
}

void combine(int *array,int l,int m, int r){
  int leftArray[m-l];
  int rightArray[r-m+1];


//add front-mid subarray to temp left array
  for(int i=0;i<=m-l;i++){
    leftArray[i]=array[l+i];
  }

//add front-mid subarray to temp left array
  for(int i=0;i<=r-m+1;i++){
    rightArray[i]=array[m+i+1];
  }
  int x=0;
  int y=0;
  int i;
    for(int i=0;i<3;i++){
      std::cout<< array[i]<<std::endl;
    }
  for(i=l;i<(r-l);i++){
    if(leftArray[x]<rightArray[y]){
      array[i]=leftArray[x++];
      //protect overflow
      if(x==(m-l+1)){
        break;
      }
    }
    else{
      array[i]=rightArray[y++];
      //protect overflow
      if(y ==(r-m)){
        break;
      }
    }
  }
  std::cout <<"test1"<<std::endl;
  //if hit break then collect all leftArray or rightArray
  while(y<(r-m+1)){
    array[i++] = rightArray[y++];
  }

std::cout <<"test2"<<std::endl;
  while(x<(m-l)){
    array[i++] = leftArray[x++];
  }
  for(int i=0;i<3;i++){
    std::cout<< array[i]<<std::endl;
  }

std::cout <<"test3"<<std::endl;

}
