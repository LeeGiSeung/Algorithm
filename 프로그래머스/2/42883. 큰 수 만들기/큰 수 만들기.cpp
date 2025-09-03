#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    //10 1 1
    for(int i = 0; i<number.size(); i++){
        while(!answer.empty() && k > 0 && answer.back() < number[i]){
            answer.pop_back();
            k--;
        }
        answer.push_back(number[i]);
    }
    
    while(k > 0){
        answer.pop_back();
        k--;
    }
    
    return answer;
}