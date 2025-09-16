#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

string removecreate(string s){
    s.erase(s.end() - 1);
    s.erase(s.begin());
    
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '('){
            s[i] = ')';
        }
        else{
            s[i] = '(';
        }
    }
    return s;
}

bool solve(string p){
    //갯수는 맞음 마지막에 제대로 닫았는지만 확인하면됨
    stack<int> s;
    for(int i = 0; i<p.size(); i++){
        if(p[i] == '(') s.push(1);
        else{
            if(s.empty()) return false;
            else s.pop();
        }
    }
    
    if(s.empty()) return true;
    else return false;
    
}

string solution(string p) {
    string answer = "";
    
    int open = 0;
    int close = 0;
    int index = 0;
    if(p == "") return "";
    //u, v에 균형잡힌 괄호 문자열 : () 갯수 같게 v는 빌 수 있음
    //아마 u에 () 갯수가 안맞은 상태면 v에 넣으라는 얘기같음
    
    for(int i = 0; i<p.size(); i++){
        if(p[i] == '(') open++;
        else if(p[i] == ')') close++;
        
        if(open == close){
            index = i + 1;
            break;
        }
    }

    string u = p.substr(0, index);
    string v = p.substr(index);
    
    //u가 "올바른 괄호 문자열" 이라면
    bool b = solve(u);
    
    if(b){ //"올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터
        answer = u + solution(v);
    }
    else{ //올바른 괄호 문자열이 아님
        answer = "(" + solution(v) + ")" + removecreate(u);
    }
    
    return answer;
}