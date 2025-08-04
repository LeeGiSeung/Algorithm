#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int dp[501][501][2];

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    memset(dp,0,sizeof(dp));
    dp[1][1][0] = 1;
    dp[1][1][1] = 1;
    //세로 가로 방향
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(city_map[i - 1][j - 1] == 1) dp[i][j][0] = dp[i][j][1] = 0; //통행 금지여서 0
            else if(city_map[i - 1][j - 1] == 0){ 
                dp[i][j][0] += (dp[i - 1][j][0] + dp[i][j - 1][1]) % MOD;
                dp[i][j][1] += (dp[i - 1][j][0] + dp[i][j - 1][1]) % MOD;
            }
            else if(city_map[i - 1][j - 1] == 2){ //방향 그대로만됨
                dp[i][j][0] += (dp[i - 1][j][0]) % MOD;
                dp[i][j][1] += (dp[i][j - 1][1]) % MOD; 
            }
        }
    }
    
    answer = (dp[m][n][0]) % MOD;
    
    return answer;
}