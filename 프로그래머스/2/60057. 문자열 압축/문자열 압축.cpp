#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = s.size();
    
    //가장 짧은 것의 길이
    //aabbaccc
    //2a2ba3c
    for(int length = 1; length <= s.size() / 2; length++){ //쌍이 되야한다는건 쌍의 최대길이는 s.sise() / 2임
        string sum = ""; //새롭게 만든 문자열
        string tmp = s.substr(0, length); 
        int cnt = 1;
        //length = 현재 쌍의 길이
        for(int i = length; i<s.size(); i+=length){
            string cur = s.substr(i, length);
            if(tmp == cur){
                cnt++;
            }
            else{
                if(cnt > 1) sum += to_string(cnt);
                sum += tmp;
                tmp = cur;
                cnt = 1;
            }
        }
        
        if(cnt > 1) sum += to_string(cnt);
        sum += tmp;
        
        int a = sum.size();
        answer = min(a , answer);
        
    }
    
    return answer;
}