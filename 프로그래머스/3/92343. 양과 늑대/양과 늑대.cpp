#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

vector<int> node[20]; //노드 연결 상태
vector<int> visit[20];
int check[20]; //노드가 양인지 늑대인지

int max_sheep = 0;
void solve(int cur, int sheep, int wolf, vector<int> visit){
    if(check[cur] == 0) sheep++;
    else if(check[cur] == 1) wolf++;
    
    if(wolf >= sheep) return;
    
    max_sheep = max(max_sheep, sheep);
    
    vector<int> newvisit;
    newvisit = visit;
    newvisit.erase(remove(newvisit.begin(), newvisit.end(), cur), newvisit.end());
    
    for(int i = 0; i<node[cur].size(); i++){
        newvisit.push_back(node[cur][i]);
    }
    
    for(int i : newvisit){
        solve(i, sheep, wolf, newvisit);
    }
    
    return;
    
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    
    check[0] = 0;
    memset(visit, 0, sizeof(visit));
    for(int i = 0; i<info.size(); i++){
        check[i] = info[i];
    }
    
    for(int i = 0; i<edges.size(); i++){
        int x = edges[i][0];
        int y = edges[i][1];
        
        node[x].push_back(y);
    }
    vector<int> v;
    v.push_back(0);
    solve(0, 0, 0, v);
    answer = max_sheep;
    return answer;
}