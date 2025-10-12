#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

vector<vector<int>> node(250010);
queue<int> tmp;

int bfs(int a){
    int cnt = -1;
    vector<bool> check(250010, false);
    
    queue<int> q;
    q.push(a);
    check[a] = true;
    
    while(!q.empty()){
        cnt++; //깊이
        tmp = q;
        int sz = q.size();
        for(int i = 0; i<sz; i++){
            int cur = q.front();
            q.pop();
            check[cur] = true;
            for(int next : node[cur]){
                if(check[next]) continue;
                check[next] = true;
                q.push(next);
            }
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    
    // 임의의 3개의 점을 뽑아 만들 수 있는 모든 f값 중에서, 제일 큰 값
    
    //n 250000
    //행의 갯수 n - 1
    
    //매번 탐색하면 무조건 시간초과임
    
    //원점(1) 에서 각 점까지의 거리를 모두 저장해놓음
    //그 뒤로 순열을 통해 최대값을 찾음
    
    for(vector<int> v : edges){
        int x = v[0];
        int y = v[1];
        node[x].push_back(y);
        node[y].push_back(x);
    }
    
    bfs(1);
    
    int dist = bfs(tmp.front());
    if(tmp.size() > 1) return dist;
    
    dist = bfs(tmp.front());
    if(tmp.size() > 1) return dist;
    
    return dist - 1;
}