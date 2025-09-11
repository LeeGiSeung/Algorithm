#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

bool check[51][51];

bool st(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

int dist[51];

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<pair<int,int>> v[51];
    memset(check, false, sizeof(check));
    
    vector<int> dist(N + 1,1e8);
    dist[1] = 0;
    sort(road.begin(), road.end(), st);
    
    for(vector<int> cur : road){
        int x = cur[0];
        int y = cur[1];
        int cost = cur[2];
        if(check[x][y] || check[y][x]) continue;
        check[x][y] = true;
        check[y][x] = true;
        //cout<<x<<" "<<y<<" "<<cost<<endl;
        v[x].push_back({y,cost});
        v[y].push_back({x,cost});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,1});
    
    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        for(int i = 0; i<v[cur].size(); i++){
            int ncur = v[cur][i].first;
            int ncost = v[cur][i].second;
            
            if(cost + ncost < dist[ncur] && cost + ncost <= K){
                dist[ncur] = cost + ncost;
                //cout<<ncur<<endl;
                pq.push({cost + ncost , ncur});
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        if (dist[i] <= K) answer++;
    }   
    
    return answer;
}