#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int pw = 1000000007;
    int mincount;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    //int dp[101][101];
    
    for(vector<int> v : puddles){
        int x = v[1];
        int y = v[0];
        
        dp[x][y] = -1;
    }
    
    dp[1][1] = 1;
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(i == 1 && j == 1) continue;
            int a = 0;
            int b = 0;
            //i 혹은 j가 1이면 가장 가장자리임 가장자리는 경우의 수가 딱 1밖에없 이전거 그대로 들고옴
            if(dp[i][j] == -1) continue; //물가면 그냥 넘김
            if(dp[i - 1][j] != -1) a = dp[i-1][j];
            if(dp[i][j - 1] != -1) b = dp[i][j-1];
   
            dp[i][j] = (a+b) % pw;
            
        }
    }
    
    return dp[n][m] % pw;
}