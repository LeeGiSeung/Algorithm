#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Data{
    int num;
    int count;
};

bool st(Data &a, Data &b){
    if(a.count != b.count){
        return a.count > b.count;
    }
    else{
        return a.num < b.num;
    }
}

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    
    vector<Data> dp(e + 1); //dp : 각 숫자가 가지고있는 제일 큰 숫자
    
    for(int i = 1; i<=e; i++){
        dp[i] = {i,0};
    }
    
    for(int i = 1; i<=e; i++){
        for(int j = 1; j<=e; j++){
            if(i * j > e) break;
            dp[i * j].count += 1; //구구단으로 숫자 나온 횟수 업데이트
        }
    }
    
    sort(dp.begin(), dp.end(), st);
    
    for(int i = 0; i<starts.size(); i++){
        int cur = starts[i];
        
        //cur : 찾고자 하는 숫자
        //숫자보다 큰데
        for(int j = 0; j<=e; j++){
            if(dp[j].num >= cur){
                answer.push_back(dp[j].num);
                break;
            }
        }
    }
    
    return answer;
}