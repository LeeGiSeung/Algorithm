#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int board[102][102];
bool check[102][102];
int answer = 0;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
struct Data{
    int x;
    int y;
    int dist;
};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    memset(board, 0, sizeof(board));
    memset(check, false, sizeof(check));
    //사각형의 영역을 칠해야함
    //누적합이용해서 칠하기
    for(vector<int> v : rectangle){
        for(int i = 0; i<v.size(); i++){
            v[i] *=2;
        }
        
        int sx = v[0];
        int sy = v[1];
        int ex = v[2];
        int ey = v[3];
        
        for(int i = sx; i <= ex; i++){
            for(int j = sy; j<= ey; j++){
                board[i][j] = 1;
            }
        } 
    }
    
    for(vector<int> v : rectangle){
        for(int i = 0; i<v.size(); i++){
            v[i] *=2;
        }
        
        int sx = v[0];
        int sy = v[1];
        int ex = v[2];
        int ey = v[3];
        
        for(int i = sx + 1; i < ex; i++){
            for(int j = sy + 1; j< ey; j++){
                board[i][j] = 0;
            }
        } 
    }
    
    queue<Data> q;
    q.push({characterX * 2,characterY * 2, 0});
    check[characterX * 2][characterY * 2] = true;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int dist = q.front().dist;
        q.pop();
        
        if(x == itemX * 2 && y == itemY * 2){
            answer = dist / 2;
            break;
        }
        
        else{
            for(int i = 0; i<4; i++){
                int nx = x + dx[i];
                int ny = y+ dy[i];

                if(nx < 0 || nx > 101 || ny < 0 || ny > 101) continue;
                if(check[nx][ny]) continue;
                if(board[nx][ny] == 0) continue; //board에서 사각형이 아니면 continue;
                check[nx][ny] = true;
                q.push({nx,ny,dist + 1});
            }
        }
    }
    
    return answer;
}