#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> node(100001);
vector<bool> check(100001, false);
int answer = 0;

void dfs(int my, int par){
    for(int i = 0; i<node[my].size(); i++){
        if(node[my][i] != par){ //역으로 거슬러 올라가는건 안됨
            dfs(node[my][i], my);
            if(!check[my] && !check[node[my][i]]){
                answer++;
                check[my] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    
    for(vector<int> v : lighthouse){
        node[v[0]].push_back(v[1]);
        node[v[1]].push_back(v[0]);
    }
    
    dfs(1,1);
    
    return answer;
}