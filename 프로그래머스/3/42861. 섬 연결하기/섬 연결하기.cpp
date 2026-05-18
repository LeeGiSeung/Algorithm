#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <queue>
using namespace std;

vector<vector<int>> island(100, vector<int>(100, 0));

struct Info{
    int x;
    int y;
    int cost;
    
    Info(int _x, int _y, int _cost){
        x = _x;
        y = _y;
        cost = _cost;
    }
    
    bool operator<(const Info &other) const{
        return cost > other.cost;
    }
};

vector<int> parent_num(100, 0);

int find_num(int num){
    if(parent_num[num] == num) return num;
    return find_num(parent_num[num]);
}

void union_find(int x, int y){ //x,y 연결
    int xp = find_num(x);
    int yp = find_num(y);

    if(xp < yp){
        parent_num[yp] = xp; 
    }
    else{
        parent_num[xp] = yp;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    //priority_queue;
    //모든 섬이 서로 통행 가능하도록 필요한 최소 비용
    
    priority_queue<Info> pq;
    
    for(int i = 0; i<n; i++){
        parent_num[i] = i; //일단 자기 자신 부모로 설정
    }
    
    for(int i = 0; i<costs.size(); i++){
        pq.push(Info(costs[i][0],costs[i][1],costs[i][2]));
    }
    
    //같은 섬에 속해있는지도 봐야하니까 유니온 파인드도 해야함
    
    while(!pq.empty()){
        //cost가 가장 적은 섬부터 정렬돼있음
        Info cur = pq.top();
        pq.pop();
        
        if(find_num(cur.x) == find_num(cur.y)) continue; //이미 연결된 섬이면 지나감
        //if(island[cur.x][cur.y] != 0) continue; //이미 지정돼있으면 하면 안됨 이미 최소값임
        union_find(cur.x, cur.y);
        answer += cur.cost; //가격 더해주고
        island[cur.x][cur.y] = cur.cost;
    }
    
    return answer;
}