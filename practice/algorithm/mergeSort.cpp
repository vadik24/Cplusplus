#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//create a merge sort algorithm
//divide array into subarray left & right
//conquer two leaf child
//combine two subarray into one
// divide/conquer is O(logN), Merge two array into one O(N) so O(nlogN)

long mergeSort(int *array,int l, int r);
long combine(int *array,int l,int m,int r);
int main(){

  ifstream myfile;
  myfile.open("array.txt");
  int value;
  int i=0;
  int array[100000];
  while(myfile >> value){
  array[i++] =value;
}
  myfile.close();
  int length = sizeof(array)/sizeof(array[0]);

  long countInverse =0;
  countInverse = mergeSort(array,0,length-1);
  cout << countInverse <<  " " <<length<<endl;
return 0;

}


//sort the array
//element l-left r-right of array
long mergeSort(int* array,int l,int r){
  //check if it leaf problem else do subproblem
  if(array == 0 || r-l==0){
    return 0;
  }
  // added +1 to make it left two node and right one nod
  int m = (l+r)/2;
  long x=0,y=0,z=0;
  //left
  x=mergeSort(array,l,m);
  //right
  y=mergeSort(array,m+1,r);
  //hit end subproblem,conquer
  z=combine(array,l,m,r);
  return x+y+z;

}

long combine(int *array,int l,int m, int r){
  int lLength= m-l+1;
  int rLength = r-m;
  int leftArray[lLength];
  int rightArray[rLength];
  long  countInverse=0;

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

        countInverse+=lLength-ll;
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
  return countInverse;
}
