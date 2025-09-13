#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>> pq;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    if(k >= enemy.size()) return enemy.size();
    //남은 병사의 수보다 현재 라운드의 적의 수가 더 많으면 게임이 종료
    //무적권을 사용하면 병사의 소모없이 한 라운드의 공격을 막을 수 있습니다
    //무적권은 최대 k번 사용할 수 있습니다.
    
    //모든 라운드를 막을 수 있는 경우에는 enemy[i]
    
    for(int i = 0; i<enemy.size(); i++){
        pq.push(enemy[i]);
        n-=enemy[i];
        
        if(n < 0){
            if(k > 0){
                k--;
                n += pq.top();
                pq.pop();
            }
            else{
                break;
            }
        }
        answer++;
    }
    
    return answer;
}