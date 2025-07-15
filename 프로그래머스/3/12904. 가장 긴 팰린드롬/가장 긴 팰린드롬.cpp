#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string s)
{
    
    vector<vector<bool>> check(2501, vector<bool>(2501, false));
    int answer=1;
    int n = s.size();
    for(int i = 0; i<s.size(); i++){
        check[i][i] = true;
    }
    
    for(int len = 2; len <=n; len++){
        for(int i = 0; i<=n - len; i++){
            int j = i + len - 1;
            
            if(s[i] == s[j]){
                if(len == 2){
                    check[i][j] = true;
                }
                
                if(check[i + 1][j - 1]) check[i][j] = check[i + 1][j - 1];
                
                if(check[i][j]) answer = max(answer, len);
            }
        }
    }
    
    return answer;
}