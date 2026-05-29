#include <vector>
#include <algorithm>

using namespace std;

// 상, 하, 좌, 우 방향 벡터
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int r,c;

// 반환값: { 내가 이기는가(bool), 현재 시점부터 최종 종료까지의 총 이동 횟수(int) }
pair<bool, int> game(int board_mask, int x1, int y1, int x2, int y2) {
    int mypos = c*x1+y1;
    //0111
    //1000
    int wincount = 1e9;
    int losscount = 0;
    bool win = false;
    bool hasmove = false;
    
    if(!(board_mask & (1<<mypos))){
        return {false, 0};
    }
    
    for(int i = 0; i<4; i++){
        
        int nx = dx[i] + x1;
        int ny = dy[i] + y1;
        
        int nextpos = c*nx+ny;
        
        if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if(!(board_mask & (1<<nextpos))) continue; //낭떠러지면안됨
        hasmove = true;
        auto gameresult = game(board_mask ^ (1<<mypos), x2,y2,nx,ny);
        
        if(!gameresult.first){
            wincount = min(wincount, gameresult.second + 1);
            win = true;
        }
        else{
            losscount = max(losscount, gameresult.second + 1);
        }
        
    }
    if(!hasmove){
        return{false, 0};
    }
    
    return {win, win ? wincount : losscount };
    
    
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    r = board.size();
    c = board[0].size();
    
    // 1단계: 2차원 board 배열을 하나의 정수(비트마스크)로 압축
    // 1은 발판 있음, 0은 발판 없음
    int initial_mask = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == 1) {
                initial_mask |= (1 << (c * i + j));
            }
        }
    }

    // 게임 시작 (처음엔 A가 현재 플레이어, B가 대기 플레이어)
    return game(initial_mask, aloc[0], aloc[1], bloc[0], bloc[1]).second;
}