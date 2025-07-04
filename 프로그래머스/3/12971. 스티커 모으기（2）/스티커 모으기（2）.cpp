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
    
    //1번째 스티커를 뜯는 경우
    dp[0] = sticker[0];
    dp[1] = sticker[0];
    
    for(int i = 2; i<sticker.size() - 1; i++){
        dp[i] = max(dp[i - 2] + sticker[i], dp[i-1]);
        answer = max(dp[i], answer);
    }
    answer = max(answer, sticker[sticker.size() - 2]);
    //2번째 스티커를 뜯는 경우
    dp[0] = 0;
    dp[1] = sticker[1];
    
    for(int i = 2; i<sticker.size(); i++){
        dp[i] = max(dp[i - 2] + sticker[i], dp[i-1]);
        answer = max(dp[i], answer);
    }
    answer = max(answer, sticker[sticker.size() - 1]);
    
    return answer;
}