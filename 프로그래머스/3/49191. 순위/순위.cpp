#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool check[102][102];


int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(int i = 0; i<results.size(); i++){
        int x = results[i][0];
        int y = results[i][1];
        
        check[x][y] = true;
        //x가 y를 이겼다.    
    }
    
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<=n; j++){
            for(int k = 1; k<=n; k++){
                if(check[j][i] && check[i][k]){
                    check[j][k] = true;
                }
            }    
        }
    }
    
    for(int i = 1; i<=n; i++){
        int count = 0;
        for(int j = 1; j<=n; j++){
            if(check[i][j] || check[j][i]){
                count++;
            }
        }
        if(n-1 == count) answer++;
    }
    
    
    return answer;
}