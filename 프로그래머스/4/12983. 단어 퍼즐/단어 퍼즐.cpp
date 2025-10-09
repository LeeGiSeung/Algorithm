#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

int dp[20001];

int solution(vector<string> strs, string t)
{
    int answer = -1;
    bool flag = true;
    dp[0] = 0;
    for(int i = 1; i<=t.size(); i++){
        dp[i] = 1e8;
    }
    
    int idx = 0;
    int n = t.size();
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<strs.size(); j++){
            idx = i - strs[j].size();
            if(idx < 0) continue;
            flag = true;
            
            for(int z = 0; z<strs[j].size(); z++){
                if(strs[j][z] != t[idx + z]){
                    flag = false;
                    break;
                }
            }
            if(flag) dp[i] = min(dp[i],dp[idx] + 1);
        }
    }

    if(dp[n] == 1e8) return -1;
    
    return dp[n];
}