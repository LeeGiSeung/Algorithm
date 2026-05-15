#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n,0);
    
    stack<int> st;
    int i;
    for(i = 0; i<n; i++){
        while(!st.empty() && prices[st.top()] > prices[i]){ //st가 안비어있고 주식이 내려갔을때
            int stTop = st.top();
            st.pop();
            
            answer[stTop] += i - stTop;
            
        }
        
        st.push(i);
    }
    
    st.pop();
    i--;
    while(!st.empty()){
        int stTop = st.top();
        st.pop();

        answer[stTop] += i - stTop;
    }
    
    return answer;
}