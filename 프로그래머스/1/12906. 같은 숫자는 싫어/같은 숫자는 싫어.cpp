#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    //연속적으로 나타나는 숫자 제거
    
    stack<int> s;
    
    for(int i : arr){
        if(s.empty()){
            s.push(i);
        }
        else if(s.top() != i) s.push(i);
    }
    
    while(!s.empty()){
        answer.push_back(s.top());
        s.pop();
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}