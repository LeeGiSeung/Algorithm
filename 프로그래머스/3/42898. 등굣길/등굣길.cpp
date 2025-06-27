#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
int check[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    //puddles 물에 잠긴 지역 0~10개
    memset(check, 1e8, sizeof(check));
    
    for(int i = 0; i<puddles.size(); i++){
        int x = puddles[i][0];
        int y = puddles[i][1];
        check[x][y] = -1; //연못으로 설정
    }
    
    for(int i = 0; i<=m; i++){
        check[i][0] = 0;
    }
    
    for(int i = 0; i<=n; i++){
        check[0][n] = 0;
    }
    
    check[1][1] = 1;
    
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(i == 1 && j == 1) continue;
            if(check[i][j] == -1) continue; //연못이면 넘어감
            if(check[i - 1][j] == -1){
                check[i][j] = check[i][j-1] % 1000000007;
            }
            else if(check[i][j - 1] == -1){
                check[i][j] = check[i - 1][j] % 1000000007;
            }
            else{
                check[i][j] = (check[i][j - 1] + check[i - 1][j]) % 1000000007;
            }
        }
    }
    
    answer = check[m][n];    
    
    return answer;
}