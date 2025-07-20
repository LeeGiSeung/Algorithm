#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<bool>> check(101, vector<bool>(101, false));

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(int i = 0; i<results.size(); i++){
        check[results[i][0]][results[i][1]] = true;
    }
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            for(int k = 1; k<=n; k++){
                if(check[j][i] && check[i][k]) check[j][k] = true;
            }
        }
    }
    
    for(int i = 1; i<=n; i++){
        int count = 0;
        for(int j = 1; j<=n; j++){
            if(i == j) continue;
            
            if(check[i][j] || check[j][i]) count++;
        }
        
        if(count == n-1) answer++;
    }
    
    return answer;
}