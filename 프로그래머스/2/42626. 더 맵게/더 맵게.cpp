#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    //일단 정렬해야하는건 맞음
    for(int i : scoville) pq.push(i);

    bool done = false;
    
    while(pq.size() > 1){
        
        int x = pq.top();
        pq.pop();

        if(x >= K){
            done = true;
            break; //제일 낮은 음식의 스코빌이 k를 넘었으면 더이상 할 필요 없음
        }

        int y = pq.top();
        pq.pop();
        
        answer++;
        int newScoville = x + (y * 2);

        pq.push(newScoville);
    }
    
    if(done) return answer;
    if(pq.top() > K) return answer;
    return -1; //모든 음식의 스코빌 지수를 k이상으로 만들 수 없는 경우에는 -1 리턴
}