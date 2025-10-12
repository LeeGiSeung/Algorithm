#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Data{
    int dist;
    int x;
    int y;
    bool operator>(const Data &a) const{
        return dist > a.dist;
    }
};

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    int n = land.size();
    vector<vector<bool>> check(301, vector<bool>(301,false));
    priority_queue<Data, vector<Data>, greater<Data>> pq;

    pq.push({0,0,0});
    while(!pq.empty()){
        int dist = pq.top().dist;
        int x = pq.top().x;
        int y = pq.top().y;
        pq.pop();
        if(check[x][y]) continue;
        check[x][y] = true;
        //cout<<x<<" "<<y<<" "<<dist<<endl;
        answer += dist;
        
        for(int i = 0; i<4; i++){
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            int next = abs(land[x][y] - land[nx][ny]);
            
            if(next <= height) pq.push({0,nx,ny});
            else pq.push({next,nx,ny});
            
            
        }
        
    }
    
    return answer;
}