#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int d[201];
int dp[201][201];

int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0;
    
    d[0] = matrix_sizes[0][0];
    int m = matrix_sizes.size();
    
    for(int i = 0; i<matrix_sizes.size(); i++){
        d[i + 1] = matrix_sizes[i][1];
    }
    
    for(int n = 0; n<m; n++){
        for(int i = 1; i<= m - n; i++){
            int j = i + n;
            
            if(i == j) dp[i][j] = 0;
            else{
                dp[i][j] = 1e8;
                for (int k = i; k <= j - 1; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + d[i - 1] * d[k] * d[j]);
                }
            }
        }
    }
    
    answer = dp[1][m];
    
    return answer;
}