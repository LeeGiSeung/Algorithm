#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <map>
using namespace std;

int n, m;
int answer = 1e8;

vector<vector<int>> beginning;
vector<vector<int>> target;

void flip_row(int n){ //행 계산
        for(int j = 0; j<m; j++){
            beginning[n][j] = !beginning[n][j];
        }
}

int com_col(int m){ //열 계산
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(beginning[i][m] == target[i][m]){
            cnt++;
        }
    }
    
    if(cnt == 0) return 1;
    if(cnt == n) return 0;
    else return -1;
    
}

void dfs(int row, int cnt){ //현재 행, 돌린 횟수
    if(row == n){
        //row가 마지막까지 다 했을때
        int flag = 1;
        for(int i = 0; i<m; i++){
            int result = com_col(i);
            
            if(result == -1){
                flag = -1;
                break; //열이 이상하면 더 이상할 필요없음
            }
            cnt += result; //추가로 돌려야 하면 더함
        }
        if(flag == 1){
            answer = min(answer, cnt);
            return;
        }
    }
    else{
        dfs(row + 1, cnt);
        flip_row(row);
        dfs(row + 1, cnt + 1);
        flip_row(row);
    }
}

int solution(vector<vector<int>> _beginning, vector<vector<int>> _target) {
    beginning = _beginning;
    target = _target;
    
    n = target.size();
    m = target[0].size();
    
    dfs(0,0);
    
    //단, 목표 상태를 만들지 못하는 경우에는 -1을 return 합니다.
    if(answer == 1e8) answer = -1;
    return answer;
}