#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    multiset<int> st;
    for(string s : operations){
        int a = stoi(s.substr(s.find(" ") + 1));
        if(s[0] == 'I'){
            st.insert(a);
        }
        else if(!st.empty()){
            if(s == "D 1"){
            //최대값 빼기
            st.erase(--st.end());
            }
            else if(s == "D -1"){
                //최소값 빼기
                st.erase(st.begin());
            }
        }
    }
    
    if(st.empty()){
        answer[0] = 0; answer[1] = 0;
    }
    else{
        answer[0] = *st.rbegin();
        answer[1] = *st.begin();
    }
    
    return answer;
}