#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void solve(vector<vector<int>> &answer, int n, int from, int mid, int to){
    vector<int> r;
    if(n == 1){
        r.push_back(from);
        r.push_back(to);
        answer.push_back(r);
    }
    else{
        solve(answer, n - 1, from, to, mid);
        r.push_back(from);
        r.push_back(to);
        answer.push_back(r);
        solve(answer, n - 1, mid, from, to);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    solve(answer, n, 1,2,3);
    
    return answer;
}