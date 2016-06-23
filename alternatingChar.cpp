#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int element;
    cin >> element;
    string buffer[element];
    for(int i = 0;i<element;i++){
	cin >> buffer[i];
    }
    for(int i = 0; i< element;i++){
	int count = 0;
	for(int j = 1;j<buffer[i].length();j++){
		if(buffer[i][j] == buffer[i][j-1])
			count++;	
	}
	cout<< count << endl;
    }
return 0;
}

