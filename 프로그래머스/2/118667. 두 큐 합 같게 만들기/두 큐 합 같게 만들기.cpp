#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int ansleng = queue1.size() * 3 + 1;
    long long one = 0;
    long long two = 0;
       
    queue<int> q1;
    queue<int> q2;
    
    for(int i = 0; i<queue1.size(); i++){
        one += queue1[i];
        two += queue2[i];
        q1.push(queue1[i]);
        q2.push(queue2[i]);
    }

    while(!q1.empty() && !q2.empty()){
        
        if(ansleng < answer) return -1;
        if(one == two) return answer;
        if(one > two){
            //1이 더크니까 1에서 빼야함
            one -= q1.front();
            two += q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        else{
            two -= q2.front();
            one += q2.front();
            q1.push(q2.front());
            q2.pop();
        }
        
        answer++;

    }
    
    return -1;
}