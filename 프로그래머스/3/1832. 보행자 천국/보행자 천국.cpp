#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int Dp[510][510][2];

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
        for(int i = 0; i<=m; i++){
        for(int j = 0; j<=n; j++){
            Dp[i][j][0] = 0;
            Dp[i][j][1] = 0;
        }
    }
    Dp[1][1][0] = 1;
    Dp[1][1][1] = 1;
    
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(i == 1 && j == 1) continue;
            //city_map[i][j] 가 0일 경우
            if(city_map[i - 1][j - 1] == 0){
                Dp[i][j][0] = (Dp[i][j][0] + Dp[i - 1][j][0] + Dp[i][j - 1][1]) % MOD;
                Dp[i][j][1] = (Dp[i][j][1] + Dp[i - 1][j][0] + Dp[i][j - 1][1]) % MOD;
            }
            else if(city_map[i - 1][j - 1] == 1){
                Dp[i][j][0] = 0;
                Dp[i][j][1] = 0;
            }
            else{
                //2인 경우 회전이 안됨
                Dp[i][j][0] = Dp[i-1][j][0] % MOD;
                Dp[i][j][1] = Dp[i][j-1][1] % MOD;
            }
        }
    }
    
    answer = Dp[m][n][0] % MOD;
    
    //1이면 아예 갈 수 없다.
    //2이면 꺾을 수 있다.
    
    return answer;
}