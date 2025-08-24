#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
int dp[60001];

int solution(int n) {
    int answer = 0;
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    
    for(int i = 4; i<=n; i++){
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    }
    
    answer = dp[n] % 1000000007;
    
    return answer;
}