#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int answer = 0;
vector<vector<int>> node(18);
vector<int> info;
void dfs(int sheep, int wolf, vector<int> root){
    answer = max(sheep, answer);
    
    for(int i = 0; i<root.size(); i++){ //root : 지금 현재 갈 수 있는 후보 루트들
        int cur = root[i];
        vector<int> copy = root;
        
        copy.erase(copy.begin() + i);
        
        for(int c : node[cur]) copy.push_back(c);
        
        if(info[cur] == 0){
            dfs(sheep + 1, wolf, copy);
        }
        else{
            if(sheep > wolf + 1){
                dfs(sheep, wolf + 1, copy);
            }
        }
    }
}

int solution(vector<int> _info, vector<vector<int>> edges) {
    
    info = _info;
    
    for(vector<int> v : edges){
        node[v[0]].push_back(v[1]);
    }
    
    dfs(1,0,node[0]);
    
    return answer;
}