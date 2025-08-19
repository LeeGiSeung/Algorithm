#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
int dp[100001][4];

void check_dp(int deaph ,int temp, vector<vector<int> > &land){
    //temp 구할려고하는 위치
    for(int i = 0; i<4; i++){
        if(i == temp) continue;
        dp[deaph][temp] = max(dp[deaph - 1][i] + land[deaph][temp], dp[deaph][temp]);
    }
}

int solution(vector<vector<int> > land)
{
    memset(dp,0,sizeof(dp));
    
    int answer = 0;
    for(int i = 0; i<4; i++){
        dp[0][i] = land[0][i];
    }
    
    for(int i = 1; i<land.size(); i++){
        for(int j = 0; j<4; j++){
            check_dp(i,j, land);
        }
    }
    
    for(int i = 0; i<4; i++){
        answer = max(answer,dp[land.size() - 1][i]);
    }
    
    return answer;
}