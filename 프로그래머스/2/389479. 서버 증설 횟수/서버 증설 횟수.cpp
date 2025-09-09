#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    //m명 늘어날 때마다 서버 1대가 추가로 필요
    //어느 시간대의 이용자가 m명 미만이라면, 서버 증설이 필요하지 않습니다.
    //어느 시간대의 이용자가 n x m명 이상 (n + 1) x m명 미만이라면 최소 n대의 증설된 서버가 운영 중이어야 합니다
    //한 번 증설한 서버는 k시간 동안 운영
    
    //players[i]는 i시 ~ i+1시 사이의 게임 이용자의 수
    
    //지난 건 필요없음
    queue<pair<int,int>> q;
    int server = 0;
    for(int i = 0; i<players.size(); i++){
        //k = 5, i = 6
        //서버 지속 불가능하면 지워야함
        while(!q.empty() && q.front().first == i){
            server-= q.front().second;
            q.pop(); //서버 초기화
        }
        
        //i 현재 시간
        if(players[i] >= m){ //서버 추가해야함
            int req = players[i] / m;
            
            if(req > server){
                int newserver = req - server;
                server += newserver;
                answer += newserver;
                q.push({i + k, newserver});
            }
            
        }
    }
    
    return answer;
}