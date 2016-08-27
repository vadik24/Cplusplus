#include <iostream>
//create a merge sort algorithm
//divide array into subarray left & right
//conquer two leaf child
//combine two subarray into one
// divide/conquer is O(logN), Merge two array into one O(N) so O(nlogN)

void mergeSort(int *array,int l, int r);
void combine(int *array,int l,int m,int r);
int main(){
  int array[] = {7,3,2,5,1,4,9,8,123,42,44,33,88};
  int length = sizeof(array)/sizeof(array[0]);
  mergeSort(array,0,length-1);
  for(int i=0;i<length;i++){
    std::cout<< array[i]<< " ";
  }
  std::cout << std::endl;
  return 0;
}

//sort the array
//element l-left r-right of array
void mergeSort(int* array,int l,int r){
  //check if it leaf problem else do subproblem
  if(array == 0 || r-l==0){
    return;
  }
  // added +1 to make it left two node and right one nod
  int m = (l+r)/2;

  //left
  mergeSort(array,l,m);
  //right
  mergeSort(array,m+1,r);
  //hit end subproblem,conquer
  combine(array,l,m,r);

  for(int i=0;i<8;i++){
    std::cout<< array[i]<< " ";
  }
  std::cout << std::endl;

}

void combine(int *array,int l,int m, int r){
  int lLength= m-l+1;
  int rLength = r-m;
  int leftArray[lLength];
  int rightArray[rLength];


  // left sort temparray
  for(int i=0;i<lLength;i++){
    leftArray[i] = array[l+i];
  }
  //right sort temparray
  for(int i=0;i<rLength;i++){
    rightArray[i] = array[m+i+1];
  }

  int ll=0,rr=0,i=l;
  //each lowest value of two temparray into one array
  //until one of temparray hit the limit
  while(ll<lLength && rr<rLength){
    if(rightArray[rr]<leftArray[ll]){
      array[i] = rightArray[rr++];
    }
    else{
      array[i] = leftArray[ll++];
    }
    i++;
  }
  //first while loop, put all values in left array if didn't hit limit
  //if left array did hit limit then collect data from right array
  while(ll<lLength){
    array[i++] = leftArray[ll++];
  }

  while(rr<rLength){
    array[i++] = rightArray[rr++];
  }

}
