#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int dp[1000001];
int solution(int x, int y, int n) {
    int answer = -1;

    memset(dp,1000001,sizeof(dp));
    
    dp[y] = 0;
    
    for(int i = y; i > x; i--){
        if(i - n > 0) dp[i - n] = min(dp[i] + 1, dp[i - n]);
        if(i % 2 == 0) dp[i / 2] = min(dp[i / 2], dp[i] + 1);
        if(i % 3 == 0) dp[i / 3] = min(dp[i / 3], dp[i] + 1);
    }

    if(dp[x] >= 1000001) answer = -1;
    else answer = dp[x];
    
    return answer;
}