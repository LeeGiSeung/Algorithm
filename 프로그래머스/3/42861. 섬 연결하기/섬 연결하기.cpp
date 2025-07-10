#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int cur;
    int dist;
    
    bool operator<(const Node& other) const {
        return dist > other.dist;   
    }
};

bool check[101];

//다리를 여러 번 건너더라도, 도달할 수만 있으면 통행 가능하다고 봅니다.
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    priority_queue<Node> pq;
    pq.push({0,0});
    
    while(!pq.empty()){
        Node cur_node = pq.top();
        pq.pop();
        
        if(check[cur_node.cur]) continue;
        
        check[cur_node.cur] = true;
        answer += cur_node.dist;
        //cout<<cur_node.cur<<" 확인"<<endl;
        for(int i = 0; i<costs.size(); i++){
            if(costs[i][0] == cur_node.cur){
                pq.push({costs[i][1], costs[i][2]});
            }
            else if(costs[i][1] == cur_node.cur){
                pq.push({costs[i][0], costs[i][2]});
            }
        }
    }
    
    return answer;
}