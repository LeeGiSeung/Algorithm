#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int check[26][26][2];
int dx[4] = {-1,1,0,0}; //상, 하, 좌, 우
int dy[4] = {0,0,-1,1};

struct Data{
    int x;
    int y;
    int dir;
    int dist;
};

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    queue<Data> q;
    q.push({0,0,0,0});
    q.push({0,0,1,0});
    for(int i = 0; i < 26; i++)
    for(int j = 0; j < 26; j++)
        for(int k = 0; k < 2; k++)
            check[i][j][k] = 1e8;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().dir;
        int dist = q.front().dist;
        q.pop();
        //0 1 수직, 수평
        
        if(x == n - 1 && y == n - 1){
            check[x][y][dir] = min(check[x][y][dir], dist);
            continue;
        }
        
        //0 1 상하
        //2 3 좌우
        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ndist = dist + 100; //일단 기본적으로 100은 추가됨
            int ndir = 0;
            
            if(dir == 0){ // 현재 수직
                if(i == 2 || i == 3) ndist += 500; // 수평 이동이면 코너
            } else { // 현재 수평
                if(i == 0 || i == 1) ndist += 500; // 수직 이동이면 코너
            }
                
            ndir = (i < 2 ? 0 : 1);
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue; //범위 넘으면 안됨
            if(check[nx][ny][ndir] <= ndist) continue;
            if(board[nx][ny] == 1) continue;
            
            check[nx][ny][ndir] = ndist;
            q.push({nx,ny,ndir,ndist});
        }
    }
    
    answer = min(check[n - 1][n - 1][0], check[n - 1][n - 1][1]);
    
    return answer;
}