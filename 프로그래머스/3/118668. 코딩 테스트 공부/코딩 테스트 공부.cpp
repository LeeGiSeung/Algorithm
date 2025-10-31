#include <string>
#include <vector>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    
    int n = 0;
    int m = 0;
    
    for(vector<int> v : problems){
        n = max(v[0], n);
        m = max(v[1], m);
    }
    
    if(alp > n){
        alp = n;
    }
    if(cop > m){
        cop = m;
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e8));
    dp[alp][cop] = 0;
    
    for(int i = alp; i<= n; i++){
        for(int j = cop; j <= m; j++){
            if(i + 1 <= n){
                dp[i + 1][j] = min(dp[i][j] + 1, dp[i + 1][j]);
            }
            if(j + 1 <= m){
                dp[i][j + 1] = min(dp[i][j] + 1, dp[i][j + 1]);
            }
            for(vector<int> p : problems){
                if(p[0] <= i && p[1] <= j){
                    dp[min(i + p[2], n)][min(j + p[3], m)] = 
                        min(dp[min(i + p[2], n)][min(j + p[3], m)], 
                           dp[min(i,n)][min(j,m)] + p[4]
                   );
                }
            }
        }
    }
    
    return dp[n][m];
}