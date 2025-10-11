#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
vector<vector<int>> node(200001);

vector<bool> check(200001, false);
vector<int> tmp(200001, 0);
vector<int> go(200001, 0);

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    
    for(vector<int> v : path){
        int x = v[0];
        int y = v[1];
        
        node[x].push_back(y);
        node[y].push_back(x);
    }
    
    //order안에는 이전에 방문해야 하는게 정해져있음
    for(vector<int> v : order) tmp[v[1]] = v[0];
    
    //dfs로 천천히 진행하다가 막힌걸 만나면 다시 뒤돌아가야함
    
    if(tmp[0] != 0) return false; //0진입부터 뭐가 있으면 안됨
    check[0] = true;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        for(int i = 0; i<node[x].size(); i++){
            int next = node[x][i];
            if(check[next]) continue; //방문했던 노드면 x
            
            //6 7
            if(tmp[next] != 0 && !check[tmp[next]]){
                //먼저 방문해야 하는 곳이 있으면,
                //go에 먼저 방문한 곳을 방문하면 지금 node를 queue에 넣도록
                go[tmp[next]] = next;
                continue;
            }
            check[next] = true;
            q.push(next); //정상적으면 그냥 들어감
            
            if(go[next] != 0 && !check[go[next]]){
                check[go[next]] = true;
                q.push(go[next]);
                continue;
            }
        }
    }
    
    for(int i = 0; i<n; i++){
        if(!check[i]) return false;
    }
    
    return true;
}