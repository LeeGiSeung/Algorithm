#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int find_pel(string s,int _left, int _right){

    //cout<<"검사 시작"<<_left<<" "<<_right<<endl;
    
    while(_left >= 0 && _right < s.size()){
        //cout<<"검사 중"<<_left<<" "<<_right<<endl;
        if(s[_left] != s[_right]){
            break;
        }
        _left -= 1;
        _right += 1;
    }
    
    return _right - _left - 1;
    
}

int solution(string s)
{
    int answer=0;
    vector<string> v;
    int hol = 0;
    int jjak = 0;
    
    for(int i = 0; i<s.size(); i++){
        hol = find_pel(s, i, i);
        jjak = find_pel(s, i, i + 1);
        
        int cur = max(hol, jjak);
        answer = max(answer, cur);
        
    }

    return answer;
}