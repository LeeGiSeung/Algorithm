#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq(works.begin(), works.end());

    while(n-- > 0 && !pq.empty()){
        int top = pq.top(); pq.pop();
        if(top == 0) break; // 이미 모든 일이 0이면 종료
        pq.push(top - 1);
    }

    while(!pq.empty()){
        long long w = pq.top(); pq.pop();
        answer += w * w;
    }

    return answer;
    
}

int main(){
    
    return 0;
}