#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int minrange = 1e9;

    //10일 연속으로 일치할 경우에 맞춰서
    unordered_map<string,int> junghyun;
    unordered_map<string,int> market;
    for(int i = 0; i<want.size(); i++){
        junghyun[want[i]] = number[i];
    }
    
    for(int i = 0; i<10; i++){
        market[discount[i]]++;
    }
    
    if(junghyun == market){ //같은 날이면
        answer++;
    }
    
    for(int day = 10; day<discount.size(); day++){
        
        market[discount[day]]++;
        market[discount[day-10]]--;
        
        if(market[discount[day-10]] == 0){
            market.erase(discount[day-10]);
        }
        
        if(junghyun == market){ //같은 날이면
            answer++;
        }   
    }
    

    
    return answer;
}