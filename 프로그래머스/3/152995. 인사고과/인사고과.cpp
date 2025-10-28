#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool st(vector<int> &a, vector<int> &b){
    if(a[0] == b[0]) return a[1] < b[1];
    else return a[0] > b[0];
}

int solution(vector<vector<int>> scores) {
    int answer = 0;
    
    int wana = scores[0][0];
    int wanb = scores[0][1];
    int wansum = wana + wanb;
    
    sort(scores.begin(), scores.end(), st);
    
    int index = 1;
    int maxb = 0;
    
    for(int i = 0; i<scores.size(); i++){
        int a = scores[i][0];
        int b = scores[i][1];
        //1 3 5 10 2
        if(maxb > b){
            if(a == wana && b == wanb) return -1;
        }
        else{
            maxb = max(maxb, b);
            if(a + b > wansum) index++;
        }
        
    }
    
    return index;
}