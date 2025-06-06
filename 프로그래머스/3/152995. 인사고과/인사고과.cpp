#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> v;

bool solve(const vector<int>& a, const vector<int>& b){
    if(a[0] == b[0]) return a[1] < b[1];
    else return a[0] > b[0];
}

int solution(vector<vector<int>> scores) {
    
    int answer = 1;
    
    int x = scores[0][0];
    int y = scores[0][1];
    
    if(scores.size() == 1) return 1;
    
    sort(scores.begin(), scores.end(), solve);
    
    int max_y = 0;
    for(auto& s : scores){
        if(s[0] > x && s[1] > y) return -1;
        
        if(s[1] >= max_y){
            
            max_y = s[1];
            v.push_back(s[0] + s[1]);
        }
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    for(int i = 0; i<v.size(); i++){
        if(v[i] > x + y){
            answer++;
        }
        else{
            break;
        }
    }
    
    return answer;
}