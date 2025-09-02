#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0; //시간
    int max_car = truck_weights.size();
    //다리에 올라갈 수 있는 트럭 수 bridge_length
    //다리가 견딜 수 있는 무게 weight
    //트럭 별 무게 truck_weights
    
    int cur_weight = 0;
    int cdx = 0;
    queue<int> q;
    while(1){
        
        if(cdx == max_car){
            answer += bridge_length;
            break;
        }
        
        if(q.size() == bridge_length){
            cur_weight -= q.front();
            q.pop();
        }
        
        answer++; //시간 증가
        
        if(cur_weight + truck_weights[cdx] > weight){ //만약 현재 다리에 새로운 차를 넣었을때 넘어가면
            //차를 못넘음
            q.push(0);
        }
        else{
            //아니면 차 넣을 수 있음
            q.push(truck_weights[cdx]);
            cur_weight += truck_weights[cdx]; //다리무게증가
            cdx++; //차 순서 증가
        }
    }
    
    
    return answer;
}