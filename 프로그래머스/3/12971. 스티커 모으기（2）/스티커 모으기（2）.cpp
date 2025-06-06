#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100001];

int solution(vector<int> sticker)
{
    if(sticker.size() <= 1){
        return sticker[0];
    }
    else if(sticker.size() == 2){
        return max(sticker[0], sticker[1]);
    }
    
    int answer =0;
    dp[0] = sticker[0];
    dp[1] = sticker[0];
    //dp로 해결
    
    for(int i = 2; i < sticker.size() - 1; i++){ //처음 스티커를 땐 경우

        if(dp[i - 1] < dp[i - 2] + sticker[i]){
            dp[i] = dp[i - 2] + sticker[i];
        }
        else{
            dp[i] = dp[i-1];
        }
        
        answer = max(dp[i], answer);
    }


    dp[0] = 0;
    dp[1] = sticker[1];
    //dp로 해결
    
    for(int i = 2; i<sticker.size(); i++){ //두번째 스티커를 땐 경우
        if(dp[i - 1] < dp[i - 2] + sticker[i]){
            dp[i] = dp[i - 2] + sticker[i];
        }
        else{
            dp[i] = dp[i-1];
        }
        
        answer = max(dp[i], answer);
    }
    
    return answer;
}