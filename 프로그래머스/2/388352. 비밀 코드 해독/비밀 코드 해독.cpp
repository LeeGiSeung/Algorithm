#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solve(vector<int> &combi, vector<vector<int>> &q, vector<int> &ans){
    //combi 현재 비밀코드 [2, 3, 4, 3, 3]
    //q 기존 비밀코드
    //ans 정답 갯수 [2, 3, 4, 3, 3]

    for(int i = 0; i<q.size(); i++){
        int count = 0;
        for(int j = 0; j<combi.size(); j++){
            if(find(q[i].begin(), q[i].end(), combi[j]) != q[i].end()) count++;
        }
        
        if(count != ans[i]){
            return false;
        }
    }
    
    return true;
    
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    
    vector<int> v; //v는 가능한 비밀 코드들
    for(int i = 1; i<=n; i++){
        v.push_back(i);
    }
    
    vector<bool> check(n, false);
    fill(check.begin(), check.begin() + 5, true);
    
    do{
        vector<int> combi;
        
        for(int i = 0; i<n; i++){
            if(check[i]) combi.push_back(v[i]);
        }

        if(solve(combi,q,ans)) answer++;
    
    }while(prev_permutation(check.begin(), check.end()));
    
    return answer;
}