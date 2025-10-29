#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    
    if(sticker.size() == 1) return sticker[0];
    
    int dp[100001];
    int n = sticker.size();
    dp[0] = sticker[0];
    dp[1] = sticker[0]; //첫번째 장을 뗀거
    
    for(int i = 2; i<n-1; i++){
        dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
        answer = max(answer, dp[i]);
    }
    
    answer = max(answer, dp[n - 2]);
    
    dp[0] = 0;
    dp[1] = sticker[1]; //두번째
    
    for(int i = 2; i<n; i++){
        dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
        answer = max(answer, dp[i]);
    }
 answer = max(answer, dp[n - 2]);
    return answer;
}