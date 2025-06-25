#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool check[51];
int answer = 1e8;

void solve(string begin, string target, vector<string> words, int count){
    //cout<<begin<<" 과 "<<target<<"비교"<<endl;
    if(begin == target){
        answer = min(answer, count);
        return;
    }

    for(int i = 0; i<words.size(); i++){
        if(check[i]) continue;
        int ct = 0;
        int index = 0;
        for(int j = 0; j<words[i].size(); j++){
            if(begin[j] != words[i][j]) ct++;
            
            if(ct >= 2) continue;
        }
        if(ct <= 1){
            check[i] = true;
            //cout<<words[i]<<" 로 이동"<<endl;
            solve(words[i], target, words, count + 1);
            check[i] = false;
        }
    }
    return;
}

int solution(string begin, string target, vector<string> words) {
    
    solve(begin, target, words, 0);
    
    if(answer == 1e8) answer = 0;
    
    return answer;
}