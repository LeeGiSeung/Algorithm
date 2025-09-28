#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long dp[5001];

int solution(int n) {
    int answer = 0;
    if(n % 2 != 0) return 0;
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;

    for(int i = 4; i<=n; i+=2){
        dp[i] = (dp[i - 2] * 3) % 1000000007;
        for(int j = i - 4; j>=0; j-=2){
            dp[i] += (dp[j] * 2) % 1000000007;
        }
    }
    answer = dp[n] % 1000000007;
    return answer;
}