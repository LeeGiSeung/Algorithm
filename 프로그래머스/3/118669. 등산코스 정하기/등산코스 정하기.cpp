#include <string>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> answer;
vector<pair<int,int>> path[50001];
int intensity[50001];
bool isSummit[50001];

void solve(vector<int> &v){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<pair<int,int>> temp;
    
    memset(intensity,-1, sizeof(intensity));
    
    for(auto a : v){
        pq.push({0,a});
        intensity[a] = 0;
    }
    
    while(!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if(dist > intensity[node]) continue;
        
        if(isSummit[node]){
            temp.push_back({dist,node});
            continue;
        }
        
        for(auto a : path[node]){
            int next_dist = a.first;
            int next_node = a.second;
            
            if(intensity[next_node] == -1 || max(dist, next_dist) < intensity[next_node]){
                intensity[next_node] = max(dist, next_dist);
                pq.push({intensity[next_node],next_node});
            }
        }
    }
    sort(temp.begin(), temp.end());
    answer.push_back(temp[0].second);
    answer.push_back(temp[0].first);
    return;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    
    for(auto a : paths){
        path[a[0]].push_back({a[2],a[1]});
        path[a[1]].push_back({a[2],a[0]});
    }
    
    for(auto a : summits){
        isSummit[a] = true;
    }
    
    solve(gates);
    
    return answer;
}