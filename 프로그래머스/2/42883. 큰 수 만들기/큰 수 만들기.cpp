#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    stack<char> st;
    int n = number.size();
    for(int i = 0; i < n; i++){
        while(!st.empty() && k > 0 && st.top() < number[i]) {
            st.pop();
            k--; // 숫자를 하나 제거했으므로 지울 수 있는 기회 차감
        }
        st.push(number[i]);
    }
    
    while(k > 0 && !st.empty()) {
        st.pop();
        k--;
    }
    
    int sn = st.size();
    
    for(int i = 0; i<sn; i++){
        answer.push_back(st.top());
        st.pop();
    }
    
    reverse(answer.begin(), answer.end());

    return answer;
}