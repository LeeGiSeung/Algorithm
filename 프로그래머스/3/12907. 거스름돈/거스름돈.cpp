#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int dp[100001];

int solution(int n, vector<int> money) {
    int answer = 0;

    dp[0] = 1;
    
    for(int i = 0; i<money.size(); i++){
        for(int j = money[i]; j<= n; j++){
            dp[j] += dp[j - money[i]];
            dp[j] %= 1000000007;
        }
    }
    
    answer = dp[n] % 1000000007;
    
    return answer;
}