#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    //마지막에 보조 컨테이너 벨트에 보관한 상자부터 꺼내게 됩
    //1 2 3 4 5로 돼있는걸 order 순서대로 하는거임
    
    for(int i = 1; i<=order.size(); i++){
        s.push(i);
        while(!s.empty() && s.top() == order[answer]){
            s.pop();
            answer++;
        }
    }
    
    return answer;
}