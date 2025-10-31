#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> tops) {
    int answer = 0;
    
    vector<int> dp(n * 2 + 1, 0);
    vector<bool> check(n * 2 + 1, false);
    
    for(int i = 0; i<tops.size(); i++){
        if(tops[i] == 1) check[i * 2 + 1] = true;
    }
        
    dp[0] = 1;
    dp[1] = 2;
    if(check[1]) dp[1] = 3; //만약 뾰족하면 경우의 수 1개 더 늘어남
    
    for(int i = 2; i<= n*2; i++){
        if(i % 2 == 1 && check[i] == true){
            dp[i] = dp[i - 1] + dp[i - 1] + dp[i - 2];
        }
        else{
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        dp[i] %= 10007;
    }
    
    return dp[n*2] % 10007 ;
}