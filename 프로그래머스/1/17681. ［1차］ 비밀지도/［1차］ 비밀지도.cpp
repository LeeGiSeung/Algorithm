#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i<n; i++){
        int x = arr1[i] | arr2[i];
        
        int ch = 1;
        string s = "";
        for(int j = 0; j<n; j++){
            if(x & ch){ //
                s += "#";
            }
            else{
                s += " ";
            }
            ch<<=1;
        }
        reverse(s.begin(), s.end());
        answer.push_back(s);
    }
    
    return answer;
}