#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Data{
    int del;
    int pick;
};

void deliver(int &delpoint, int &delcount, vector<int> &deliveries, int cap, vector<int> &truck){
    while(truck[0] > 0 && delpoint >= 0){
        //truck[1] 배달 횟수가 많이 남았으면 계속 배달할 수 있음
        if(truck[0] - deliveries[delpoint] < 0){ //현재 배달 용량보다 deliveries[point]에 배달해야할 양이 많으면
            deliveries[delpoint] -= truck[0];
            delcount -= truck[0];
            truck[0] = 0;
        }
        else{ //배달하기 충분하면 지금 배달하고 point--를 통해 새로운 배달지를 찾음
            truck[0] -= deliveries[delpoint];
            delcount -= deliveries[delpoint];
            deliveries[delpoint] = 0;
            while(deliveries[delpoint] == 0 && delpoint >= 0){
                delpoint--;
            }
        }
    }
    //cout<<delpoint<<" 배달 포인트 업데이트 "<<deliveries[delpoint]<<endl;
}

void pickup(int &pickpoint, int &pickcount, vector<int> &pickups, int cap, vector<int> &truck){
    while(truck[1] < cap && pickpoint >= 0){ //이때 픽업은 전부 다 할 수 있음
        int canTake = cap - truck[1];
        if(pickups[pickpoint] > canTake) {
            pickups[pickpoint] -= canTake;
            pickcount -= canTake;
            truck[1] = cap;
        } else {
            truck[1] += pickups[pickpoint];
            pickcount -= pickups[pickpoint];
            pickups[pickpoint] = 0;
            while(pickpoint >= 0 && pickups[pickpoint] == 0) pickpoint--;
        }
    }
    //cout<<pickpoint<<" 픽업 포인트 업데이트 "<<pickups[pickpoint]<<endl;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    vector<int> truck(2, 0);  
    //무조건 바깥쪽부터 돌아야함 
    int delpoint = -1;
    int pickpoint = -1;
    
    int delcount = 0;
    int pickcount = 0;
    for(int i = n - 1; i>= 0; i--){
        if(deliveries[i] != 0 && delpoint == -1){
            delpoint = i;
            //cout<<delpoint<<endl;
        }
        if(pickups[i] != 0 && pickpoint == -1){
            pickpoint = i;
            //cout<<pickpoint<<endl;
        }
        delcount += deliveries[i];
        pickcount += pickups[i];
    }
    //무조건 배달 챙기고 픽업 가져와야함
    //delpoint, pickpoint 여기부터 시작해야함
    //cout<<delpoint<<pickpoint;
    while(delcount != 0 || pickcount != 0)
    {
        if(delcount < cap) truck[0] = delcount;
        else truck[0] = cap;
        truck[1] = 0;
        
        answer += (max(delpoint , pickpoint) + 1) * 2;
        
        deliver(delpoint, delcount, deliveries, cap, truck);
        pickup(pickpoint, pickcount, pickups, cap, truck);
        
        
    }    
    
    return answer;
}