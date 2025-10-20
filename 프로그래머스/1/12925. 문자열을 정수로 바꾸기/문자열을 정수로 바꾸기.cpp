#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    if(s[0] == '-'){
        s.substr(1);
        answer = stoi(s);
        cout<<answer;
        //answer *= -1;
    }
    else{
        answer = stoi(s);
    }
    
    return answer;
}