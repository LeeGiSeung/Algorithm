#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int w = 0; //현재 다리 위 무게
    //bridge_length 트럭이 최대 올라갈 수 있는 갯수
    //weight 무게이하 까지 견딜 수 있음
    
    for(int i : truck_weights){
        q.push(i);
    }
    
    queue<pair<int,int>> bridge;
    
    while(!q.empty()){ //아직 트럭을 보낼게 남았을때
        if(w + q.front() <= weight){ //다리위에 올릴 수 있을때
            w += q.front();
            bridge.push({q.front(),0});
            q.pop();
        }
        
        int qSize = bridge.size();
        
        for(int i = 0; i<qSize; i++){
            pair<int,int> bq = bridge.front();
            bridge.pop();
            bq.second += 1;
            
            bridge.push(bq);
        }
        
        answer++;
        
        if(bridge.front().second >= bridge_length){ //다리에서 내릴 수 있으면 내림
            w -= bridge.front().first;
            
            //cout<<"time "<<answer<<" busweight : "<<bridge.front().first<<endl;
            bridge.pop();
        }
        
        
    }
    
    answer += bridge_length;
    
    return answer;
}