#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int dx2[4] = {-2,2,0,0};
int dy2[4] = {0,0,-2,2};

int sidex[4] = {-1, -1, 1, 1};
int sidey[4] = {-1 , 1, 1, -1};

bool checkrange(int nx, int ny)
{
    if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) return false;
    return true;
}

bool checkboard(int x, int y, vector<string> &board){
    //O는 빈 테이블을 의미합니다.
    //X는 파티션을 의미합니다.
    
    //P와 P사이의 거리가 1이상이거나
    //대각선에 앉은 상태에서 파티션이 반대 대각선으로 위치해있으면
    //빈자리여도 됨
    
    //십자 위치에 사람있으면 일단 안됨
    for(int i = 0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!checkrange(nx,ny)) continue;
        if(board[nx][ny] == 'P') return false; //P있으면 안됨
    }
    
    //-2 +2 위치에 사람이 존재할 경우 검사
    for(int i = 0; i<4; i++){
        int nx = x + dx2[i];
        int ny = y + dy2[i];
        if(!checkrange(nx,ny)) continue;
        if(board[nx][ny] == 'P'){ //2칸 사이에 p있을경우 사이에 파티션 있는지
            //X 있는지 검사
            int cx = x + dx[i];
            int cy = y + dy[i];
            //2 이하로 앉지 말아 빈자리여도 안됨 무조건 파티션으로만
            if(board[cx][cy] != 'X') return false; //파티션으로 안막혀있으면 안됨
        }
    }
    
    //대각선 검사
    for(int i = 0; i<4; i++){
        int nx = x + sidex[i];
        int ny = y + sidey[i];
        if(!checkrange(nx,ny)) continue;
        if(board[nx][ny] == 'P'){
            //int sidex[4] = {-1, -1, 1, 1};
            //int sidey[4] = {-1 , 1, 1, -1};
            if(i == 0){
                int cx = x - 1;
                int cy = y;
                if(!checkrange(cx,cy)) continue;
                if(board[cx][cy] != 'X') return false; //파티션 아니면 false
                cx = x;
                cy = y - 1;
                if(!checkrange(cx,cy)) continue;
                if(board[cx][cy] != 'X') return false; //파티션 아니면 false
            }
            else if(i == 1){
                int cx = x - 1;
                int cy = y;
                if(!checkrange(cx,cy)) continue;
                if(board[cx][cy] != 'X') return false; //파티션 아니면 false
                cx = x;
                cy = y + 1;
                if(!checkrange(cx,cy)) continue;
                if(board[cx][cy] != 'X') return false; //파티션 아니면 false
            }
            else if(i == 2){
                int cx = x + 1;
                int cy = y;
                if(!checkrange(cx,cy)) continue;
                if(board[cx][cy] != 'X') return false; //파티션 아니면 false
                cx = x;
                cy = y + 1;
                if(!checkrange(cx,cy)) continue;
                if(board[cx][cy] != 'X') return false; //파티션 아니면 false
            }
            else if(i == 3){
                int cx = x + 1;
                int cy = y;
                if(!checkrange(cx,cy)) continue;
                if(board[cx][cy] != 'X') return false; //파티션 아니면 false
                cx = x;
                cy = y - 1;
                if(!checkrange(cx,cy)) continue;
                if(board[cx][cy] != 'X') return false; //파티션 아니면 false
            }
        }
    }
    
    return true; //위 검사 모두 통과하면 true return
}

bool solve(vector<string> &board){
    //P는 응시자가 앉아있는 자리를 의미합니다.
    //P와 P사이의 거리가 1이상이거나
    //대각선에 앉은 상태에서 파티션이 반대 대각선으로 위치해있으면

    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            if(board[i][j] == 'P')
                if(!checkboard(i,j,board)) return false; //안되면 바로 false return 해야함
        }
    }
    return true; //모든 P에 대한 검사가 성공이면 true return
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    //5개 대기실의 크기는 모두 5x5
    
    for(int i = 0; i<places.size(); i++){
        vector<string> board(5);
        //vector<string> ["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"]
        for(int j = 0; j<5; j++){
            for(int z = 0; z<5; z++){
                board[j].push_back(places[i][j][z]);
            }
        }
        if(solve(board)) answer.push_back(1);
        else answer.push_back(0);
    }
    
    return answer;
}