#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool st(vector<int> &a, vector<int> &b){
    if(a[1] != b[1]) return a[1] < b[1];
    else return a[0] < b[0];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), st);
    
    int end = 0;
    
    for(int i = 0; i<targets.size(); i++){
        //cout<<targets[i][0]<<" "<<targets[i][1]<<endl;
        if(targets[i][0] >= end){
            answer++;
            end = targets[i][1];
            //cout<<"방어 미사일 "<<end<<endl;
        }
    }
    
    return answer;
}