#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
bool check[101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int answer = 1e8;

struct Data{
    int x;
    int y;
    int count;
};

int solution(vector<string> board) {
    
    memset(check,false,sizeof(check));
    //목표 위치에 정확하게 멈추기 위해 최소 몇 번의 이동이 필요한지
    
    //게임판 위의 장애물이나 게임판 가장자리까지 부딪힐 때까지 미끄러져 움직이는 것을 한 번의 이동
    int n = board.size();
    int m = board[0].size();
    int sx = 0;
    int sy = 0;
    bool ch = false;
    for(int i = 0; i<board.size(); i++){
        for(int j = 0; j<board[0].size(); j++){
            if(board[i][j] == 'R'){
                sx = i;
                sy = j;
                ch = true;
                break;
            }
        }
        if(ch) break;
    }
    
    queue<Data> q;
    q.push({sx,sy,0});
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int count = q.front().count;
        q.pop();
        
        if(check[x][y]) continue; //한번 흔들었떤 곳이면 똑같음
        check[x][y] = true;
        
        if(board[x][y] == 'G'){
            answer = min(answer, count);
            break;
        }
        else{
            for(int i = 0; i<4; i++){
                int nx = x; int ny = y;
                while(true){
                    int tx = nx + dx[i];
                    int ty = ny + dy[i];
                    if(tx < 0 || tx >= n || ty < 0 || ty >= m) break;
                    if(board[tx][ty] == 'D') break;
                    nx = tx;
                    ny = ty;
                }
                
                q.push({nx,ny,count + 1});
                
            }
        }
    }
    
    if(answer == 1e8) answer = -1;
    
    return answer;
}