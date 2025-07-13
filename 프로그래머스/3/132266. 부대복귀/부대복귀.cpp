#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

vector<int> node[100001];
vector<int> dist(100001, -1);
int check[100001];

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    for(vector<int> v : roads){
        node[v[0]].push_back(v[1]);
        node[v[1]].push_back(v[0]);
    }
    
    queue<pair<int,int>> q;
    q.push({destination, 0});
    
    while(!q.empty()){
        int cur = q.front().first;
        int ds = q.front().second;
        q.pop();
        
        dist[cur] = ds;
        
        for(int i : node[cur]){
            if(check[i]) continue;
            check[i] = true;
            q.push({i, ds + 1});
        }
        
    }
    
    for(int i : sources){
        if(destination == i) answer.push_back(0);
        else answer.push_back(dist[i]);
    }
    
    return answer;
}