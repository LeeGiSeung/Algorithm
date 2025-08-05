#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
bool check[50001];
int distcheck[50001];
vector<pair<int,int>> node[50001];
vector<int> answer(2,-1);
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    
    memset(distcheck, -1, sizeof(distcheck));
    for(int s : summits){
        check[s] = true;
    }
    
    for(vector<int> v : paths){
        int x = v[0];
        int y = v[1];
        int a = v[2];
        node[x].push_back({y,a});
        node[y].push_back({x,a});
    }
    
    for(int i : gates){
        pq.push({0,i});
    }
    
    while(!pq.empty()){
        int dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(check[cur]){ //산봉우리이면
            if(answer[1] == -1 || answer[1] > dist){
                answer[1] = dist;
                answer[0] = cur;
            }
            else if(answer[1] == dist && answer[0] > cur){
                answer[0] = cur;
            }
            
            continue;
        }
        
        for(int i = 0; i<node[cur].size(); i++){
            int next_cur = node[cur][i].first;
            int next_dist = node[cur][i].second;
            next_dist = max(next_dist, dist);
            
            if(distcheck[next_cur] == -1 || distcheck[next_cur] > next_dist){
                distcheck[next_cur] = next_dist;
                pq.push({next_dist, next_cur});
            }
        }
        
    }
    
    return answer;
}