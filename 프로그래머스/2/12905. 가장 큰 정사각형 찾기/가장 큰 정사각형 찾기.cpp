#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int dp[1001][1001];

int solution(vector<vector<int>> board)
{
    int answer = 0;
    memset(dp, 0, sizeof(dp));
    
    for(int i = 0; i<board.size(); i++){
        for(int j = 0; j<board[i].size(); j++){
            if(board[i][j] == 1){
                if(i == 0 || j == 0) dp[i][j] = 1;
                else{
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                }
                answer = max(answer, dp[i][j]);
            }
        }
    }
    
    return answer * answer;
}