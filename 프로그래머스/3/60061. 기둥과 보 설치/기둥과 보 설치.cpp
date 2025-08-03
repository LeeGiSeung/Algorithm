#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<vector<int>> answer;
//return 하는 배열은 x좌표 기준으로 오름차순 정렬하며, 
//x좌표가 같을 경우 y좌표 기준으로 오름차순 정렬해주세요.

bool board[101][101][2];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool sv(vector<int> &a, vector<int> &b){
    if(a[0] != b[0]) return a[0] < b[0];
    else return a[1] < b[1];
}

bool check_build(int x, int y, int type, int n){
    
    if (type == 0) {
        if (y == 0) return true; // 바닥 위
        if (x > 0 &&board[x - 1][y][1]) return true; // 오른쪽 끝 위
        if (y < n &&board[x][y][1]) return true; // 왼쪽 끝 위
        if (y > 0 &&board[x][y - 1][0]) return true; // 다른 기둥 위
    } else {
        if (y > 0 &&board[x][y - 1][0]) return true; // 왼쪽 끝 아래 기둥
        if (x < n &&y > 0 &&board[x + 1][y - 1][0]) return true; // 오른쪽 끝 아래 기둥
        if (x > 0 && x < n &&board[x - 1][y][1] && board[x + 1][y][1]) return true; // 양쪽 끝 
    }
    
    return false;
}

bool can_break(int x, int y, int type, int n){
    
    board[x][y][type] = false;
    
    if(type == 0){
        //기둥일때
        if( y < n && board[x][y + 1][0] && !check_build(x, y +1, 0, n)) return false;
        if(y < n &&board[x][y + 1][1] && !check_build(x, y + 1, 1, n)) return false;
        if(x > 0 && y < n &&board[x - 1][y + 1][1] && !check_build(x - 1, y + 1, 1, n)) return false;
    }
    else if(type == 1){
        //보일때
        if(board[x][y][0] && !check_build(x, y, 0, n)) return false;
        if(x < n &&board[x + 1][y][0] && !check_build(x + 1, y, 0, n)) return false;
        if(x > 0 &&board[x - 1][y][1] && !check_build(x - 1, y, 1, n)) return false;
        if(x < n &&board[x + 1][y][1] && !check_build(x + 1, y, 1, n)) return false; 
    }

    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    
    for(vector<int> build : build_frame){
        int x = build[0];
        int y = build[1];
        int type = build[2];
        int dobuild = build[3];
        if(dobuild == 1){
            if(check_build(x,y,type, n)){
                board[x][y][type] = true;
            };
        }
        else if(dobuild == 0){
            if(!can_break(x,y,type, n)){ // 삭제 안되면 복구
                board[x][y][type] = true;
            }
        }
    }        
    
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=n; j++){
            if(board[i][j][0]) answer.push_back({i,j,0});
            if(board[i][j][1]) answer.push_back({i,j,1});
        }
    }
    //sort(answer.begin(), answer.end(), sv);
    return answer;
}