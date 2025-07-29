#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
vector<pair<int,int>> node[201];
vector<int> solve(int cur, int n){
    vector<int> v(n + 1, 1e8);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    v[cur] = 0;
    pq.push({cur,0});
    
    while(!pq.empty()){
        int cur = pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        
        for(int i = 0; i<node[cur].size(); i++){
            int next = node[cur][i].first;
            int next_cost = node[cur][i].second + cost;
            
            if(v[next] < next_cost) continue;
            v[next] = next_cost;
            pq.push({next, next_cost});
        }
    }
    
    return v;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 1e8;
    
    for(vector<int> v : fares){
        int x = v[0]; int y = v[1]; int z = v[2];
        node[x].push_back({y,z});
        node[y].push_back({x,z});
    }
    
    vector<int> sv = solve(s,n);
    vector<int> av = solve(a,n);
    vector<int> bv = solve(b,n);
    
    for(int i = 1; i<=n; i++){
        answer = min(answer, sv[i] + av[i] + bv[i]);
    }
    
    return answer;
}