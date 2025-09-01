#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;
int answer = 0;

set<int> s;

bool isprime(int cur){
    if(cur < 2) return false;
    for(int i = 2; i * i <= cur; i++){
        if(cur % i == 0) return false;
    }
    return true;
}

void solve(string cur, string numbers ,vector<bool> &checked){
    if(!cur.empty()){ //소수판단
        int num = stoi(cur);
        if(s.find(num) == s.end()){
            s.insert(num);
            if(isprime(num)) answer++;
            
        }
    }
    for(int i = 0; i<numbers.size(); i++){
        if(checked[i]) continue;
        checked[i] = true;
        solve(cur + numbers[i], numbers, checked);
        checked[i] = false;
    }
}

int solution(string numbers) {
    
    vector<bool> checked(numbers.size(), false);
    
    solve("",numbers,checked);
     
    return answer;
}