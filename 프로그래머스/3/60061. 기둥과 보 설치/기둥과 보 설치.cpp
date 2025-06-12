#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int board[101][101][2];

bool st(const vector<int> &a, const vector<int> &b){
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

bool can_emplace(int x, int y, int a, int n){
    bool check = false;
    if(a == 0){ //기둥이면
        if(y == 0) check = true;
        if(x > 0 && board[x - 1][y][1]) check = true;
        if(y < n && board[x][y][1]) check = true;
        if(y > 0 && board[x][y-1][0]) check = true;
    }
    else if(a == 1){ //보이면
        if(y > 0 && board[x][y - 1][0]) check = true;
        if(x < n && y > 0 && board[x + 1][y - 1][0]) check = true;
        if(x > 0 && x < n && board[x - 1][y][1] && board[x + 1][y][1]) check = true;
    }
    return check;
}

bool can_delete(int x, int y, int a, int n){
    board[x][y][a] = 0;
    if(a == 0){ //기둥이면
        if(y < n && board[x][y + 1][0] && !can_emplace(x,y + 1,a,n)) return false;
        
        if(y < n && board[x][y + 1][1] && !can_emplace(x ,y + 1, 1,n)) return false;
        if(x > 0 && y < n && board[x - 1][y + 1][1] && !can_emplace(x - 1, y + 1, 1,n)) return false;
    }
    else if(a == 1){ //보이면
        
        if (board[x][y][0] && !can_emplace(x, y, 0, n)) return false;
        if (x < n && board[x + 1][y][0] && !can_emplace(x + 1,y,0,n)) return false;
        
        if(x > 0 && board[x - 1][y][1] && !can_emplace(x - 1,y,a,n)) return false;
        if(x < n && board[x + 1][y][1] && !can_emplace(x + 1,y,a,n)) return false;
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    //n 벽면의 크기
    
    //x y a b
    //x y는 기둥, 보를 서칠 또는 삭제할 좌표
    //a는 설치 할 구조물의 종류 0 : 기둥, 1 : 보
    //b는 구조물을 설치할지 , 삭제할지 0 : 삭제, 1 : 설치
    
    //벽면을 벗어나게 기둥, 보를 설치하는 경우는 없습니다.
    //바닥에 보를 설치 하는 경우는 없습니다.
    
    for(int i = 0; i<build_frame.size(); i++){
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        //x 가로 y 세로
        
        if(b == 1){ // 설치
            if(can_emplace(x,y,a,n)){
                board[x][y][a] = 1;
            }
        }
        else if(b == 0){ // 삭제
            if(!can_delete(x,y,a,n)){
                board[x][y][a] = 1;
            }
        }
    }
    
    for(int x = 0; x <= n; x++){
        for(int y = 0; y <= n; y++){
            for(int a = 0; a < 2; a++){
                if(board[x][y][a]) answer.push_back({x, y, a});
            }
        }
    }
    
    return answer;
}