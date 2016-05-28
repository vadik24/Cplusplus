#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string buffer;
    cin >> buffer;
    char alpha[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int value[26] ={0};
    for(int i= 0;i<buffer.length();i++){
        for(int j = 0;j<26;j++){
            if(alpha[j] == tolower(buffer[i])){
               value[j] =1;
            }
        }
    }
    for(int i = 0;i<26;i++){
        if(value[i] == 0){
            cout << "not pangram" << i;
            return 0;
        }
        
    }
    cout << "pangram";
    return 0;
}

