#include<bits/stdc++.h>
 
using namespace std;
 
int n;
int ans = 0;
 
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
 
int dirdx[4][10] = {
    {-3, -1, -2, -1, 0, -1, -2, -1, 0, -2},
    {0, -2, -1, -1, -1, 2, 1, 1, 1, 0},
    {3, 1, 2, 1, 0, 1, 2, 1, 0, 2},
    {0, -2, -1, -1, -1, 2, 1, 1, 1, 0}
};
 
int dirdy[4][10] = {
    {0, -2, -1, -1, -1, 2, 1, 1, 1, 0},
    {3, 1, 2, 1, 0, 1, 2, 1, 0, 2},
    {0, -2, -1, -1, -1, 2, 1, 1, 1, 0},
    {-3, -1, -2, -1, 0, -1, -2, -1, 0, -2}
};
 
int persentage[9] = {5, 2, 10, 7, 1, 2, 10, 7, 1};
int graph[501][501];
 
void moveSand(int yy, int xx, int dir) {
    int x = xx + dx[dir];
    int y = yy + dy[dir];
    if(graph[y][x] == 0) return;
    
    int locA = graph[y][x];
    int temp = locA;
    
    for(int i = 0; i < 9; i++) {
        int nx = xx + dirdx[dir][i];
        int ny = yy + dirdy[dir][i];
        int persent = persentage[i];
        int calc = (temp*persent)/100;
        
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) ans += calc;
        else graph[ny][nx] += calc;
        
        locA -= calc;
    }
    
    int aX = xx + dirdx[dir][9];
    int aY = yy + dirdy[dir][9];
    
    if(aX < 0 || aX >= n || aY < 0 || aY >= n) ans += locA;
    else graph[aY][aX] += locA;
    graph[y][x] = 0;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    
    int x = n/2;
    int y = n/2;
    int moveDist = 1;
    int dir = 0;
    
    while(true) {
        
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < moveDist; j++) {
                moveSand(y, x, dir);
                x = x+dx[dir];
                y = y+dy[dir];
            }
            dir = (dir+1)%4;
        }
        moveDist++;
        if(moveDist == n) {
            for(int i = 0; i < moveDist; i++) {
                moveSand(y, x, dir);
                x = x + dx[dir];
                y = y + dy[dir];
            }
            break;
        }
    }
    cout << ans;
}