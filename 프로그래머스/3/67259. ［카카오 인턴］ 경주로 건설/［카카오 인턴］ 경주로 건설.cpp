#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int check[26][26][2];

struct DATA{
    int x;
    int y;
    int cost;
    int direction; //0 오른쪽 1 아래쪽
};

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void bfs(int max_x, int max_y, vector<vector<int>> board){
    queue<DATA> q;
    q.push({0,0,0,0});
    q.push({0,0,0,1});
    check[0][0][0] = 0;
    check[0][0][1] = 0;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int cost = q.front().cost;
        int direction = q.front().direction;
        q.pop();
        
        if(x == max_x && y == max_y){
            continue;
        }
        
        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ncost = cost;
            //직진인지 커브인지
            if(nx < 0 || ny < 0 || nx > max_x || ny > max_y) continue; //범위 넘으면 안됨
            if(board[nx][ny] != 0) continue;
            int ndir = (i<=1) ? 0 : 1;
            if(ndir == direction){ 
                //직진
                ncost += 100;
                if(check[nx][ny][ndir] > ncost || check[nx][ny][ndir] == -1){
                    check[nx][ny][ndir] = ncost;
                    //cout<<nx<<" "<<ny<<" "<<ndir<<" "<<ncost<<endl;
                    q.push({nx,ny,ncost,direction});
                }
            }
            else{ //방향이 다르다
                ncost += 600;
                if(check[nx][ny][ndir] > ncost || check[nx][ny][ndir] == -1){
                    check[nx][ny][ndir] = ncost;
                    //cout<<nx<<" "<<ny<<" "<<ndir<<" "<<ncost<<endl;
                    q.push({nx,ny,ncost,ndir});
                }
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    memset(check,-1,sizeof(check));
    //직선 도로 하나를 만들 때는 100
    //코너를 하나 만들 때는 500원이 추가로 듭니다.
    int s = board.size() - 1;
    bfs(s,s,board);

    if(check[s][s][0] == -1){
        answer = check[s][s][1];
    }
    else if(check[s][s][1] == -1){
        answer = check[s][s][0];
    }
    else{
        answer = min(check[s][s][0],check[s][s][1]);
    }
    
    return answer;
}