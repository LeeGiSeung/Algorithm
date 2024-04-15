#include <bits/stdc++.h>

using namespace std;
typedef long long ll;  //-2^63 ~ 2^63-1
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
typedef pair<int, char> pic;
int INF = 1e9 + 7;
//512MB = 1.2억개 int
//if(nx<0||nx>=n||ny<0||ny>=m) continue;
/*int dz[6]={1,-1,0,0,0,0};
int dx[6]={0,0,1,-1,0,0};
int dy[6]={0,0,0,0,1,-1};*/ // 3차원 bfs
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n,m;
int board[8][8];
int tmp[8][8];
int ans; // 안전 영역의 최대 크기
/**
 * 1. 모든 경우에 대해서 벽을 3개 세움
 * 2. 각 경우에 대해서 안전 영역의 크기를 구함.
 * 3. 안전 영역 중 최댓값을 저장
 */
void copyArray(int des[8][8],int src[8][8]){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            des[i][j] = src[i][j];
        }
    }
}
void spreadVirus(){
    int spread[8][8];
    copyArray(spread,tmp);
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(spread[i][j]==2) q.push({i,j});
        }
    }
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(spread[nx][ny]==0){
                spread[nx][ny] = 2;
                q.push({nx,ny});
            }
        }
    }

    int cnt = 0; // 모든 경우의 안전 영역의 크기 저장
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(spread[i][j]==0) cnt++;
        }
    }
    ans = max(ans,cnt);
}
void wall(int cur){
    if(cur == 3){ // 벽 3개를 전부 세움
        spreadVirus();
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tmp[i][j]==0){
                tmp[i][j] = 1;
                wall(cur+1);
                tmp[i][j] = 0;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==0){ // 빈 칸에만 벽을 세울 수 있다
                copyArray(tmp,board);
                tmp[i][j] = 1;
                wall(1);
                tmp[i][j] = 0;
            }
        }
    }
    cout << ans;
    return 0;
}