#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

int dp[1000001];

int solution(vector<int> money) {
    int answer = 0;
    
    memset(dp, 0, sizeof(dp));
    //인접한 두 집을 털면 경보가 나온다.
    //첫번째 집을 턴다 OR 안턴다 두가지 경우
    dp[0] = money[0];
    dp[1] = money[0];
    
    for(int i = 2; i<money.size() - 1; i++){
        dp[i] = max(dp[i - 2] + money[i], dp[i - 1]);
        answer = max(answer, dp[i]);
    }
    
    dp[0] = 0;
    dp[1] = money[1];
    
    for(int i = 2; i<money.size(); i++){
        dp[i] = max(dp[i - 2] + money[i], dp[i - 1]);
        answer = max(answer, dp[i]);
    }
    
    return answer;
}