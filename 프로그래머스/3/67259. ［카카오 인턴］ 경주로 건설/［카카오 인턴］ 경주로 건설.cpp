#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct DATA{
    int x;
    int y;
    int cost;
    int direction;
};

int check[26][26][4];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int solution(vector<vector<int>> board) {
    int answer = 2e9;
    
    queue<DATA> q;
    q.push({0, 0, 0, -1}); 
 
    int dest_x = board.size() - 1;
    int dest_y = board.size() - 1;
    
    for(int i = 0; i<=dest_x; i++){
        for(int j = 0; j<=dest_y; j++){
            for(int z = 0; z<4; z++){
                check[i][j][z] = 2e9;
            }
        }
    }
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int cost = q.front().cost;
        int direction = q.front().direction;
        q.pop();
        
        if(x == dest_x && y == dest_y){ //목적지에 도착했을때
            answer = min(cost, answer);
            continue;
        }
        else{
            //direction == 0 위아래
            //direction == 1 좌우
            
            for(int i = 0; i<4; i++){ //i 0~ 1 위아래, i 2 ~ 3 좌우 
                int nx = dx[i] + x;
                int ny = dy[i] + y;
                int ndir = direction;
                int ncost = cost;
                
                if(nx > dest_x || nx < 0) continue; //범위 넘으면 안됨
                if(ny > dest_y || ny < 0) continue;
                if(board[nx][ny] == 1) continue; //갈 수 없으면 안됨
                
                if (direction == i || direction == -1) { // 같은 방향 (0==0 or 1==1)
                    ncost += 100;
                    
                } else 
                {
                    ncost += 600;                 
                }

                if(check[nx][ny][i] >= ncost){
                    check[nx][ny][i] = ncost; //check 업데이트
                    q.push({nx,ny,ncost, i});
                }
            }
        }
        
    }
    
    //더 멀리 돌아온건 먼저 온(짧은) 것 보다 먼저 올 수 없음
    
    
    return answer;
}