#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std; 
int map[100][100]; 
int m, n;
int dy[4] = { 0,0,1,-1 }; 
int dx[4] = { 1,-1,0,0 }; 
int visited[100][100]; 
int dp[100][100]; 
void dfs(int y, int x,int cnt) {
	if (dp[y][x] > cnt) {
		dp[y][x] = cnt;
	}
	else return;
	for (int i = 0; i < 4; i++) {		
		int nx = dx[i] + x; 
		int ny = dy[i] + y; 
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue; 
		if (visited[ny][nx])continue; 
		visited[ny][nx] = 1; 
		if (map[ny][nx] == 1) {
			dfs(ny, nx, cnt + 1); 
		}
		else {
			dfs(ny, nx, cnt); 
		}				
		visited[ny][nx] = 0; 
	}
}
int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0); 
	cin >> n >> m; 
	for (int i = 0; i < m; i++) {
		string s; cin >> s; 
		for (int j = 0; j < n; j++) {
			map[i][j] = s[j]-'0'; 
		}
	}
	memset(dp, 1000000, sizeof(dp)); 
	visited[0][0] = 1; 
    dfs(0, 0, 0);
	cout << dp[m - 1][n - 1]; 
	return 0; 
}