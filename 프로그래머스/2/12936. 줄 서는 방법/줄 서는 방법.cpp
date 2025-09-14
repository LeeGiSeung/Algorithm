#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long per(int k){
    if(k == 0) return 1;
    return k * per(k - 1);
}

void solve(long long k, vector<int> &v, vector<int> &answer){
    if(v.size() == 1){
        answer.push_back(v[0]);
        return;
    }
    
    long long a = per(v.size() - 1);
    for(int i = 1; i<=v.size(); i++){
        if(i * a >= k){
            //특정 번째 숫자이면
            answer.push_back(v[i - 1]);
            v.erase(v.begin() + i - 1);
            k = k-(i-1) * a;
            solve(k,v,answer);
        }
    }
    
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> v(n);
    
    for(int i = 0; i<n; i++){
        v[i] = i + 1;
    }
    
    solve(k,v,answer);
    
    return answer;
}