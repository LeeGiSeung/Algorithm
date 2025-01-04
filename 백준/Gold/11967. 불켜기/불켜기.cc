#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int n, m;
int result = 0;
bool check[101][101];
bool can[101][101];
bool light_check[101][101];
vector<pair<int,int>> light[101][101];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void solve() {
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	check[1][1] = true;
	result++;
	light_check[1][1] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < light[x][y].size(); i++) {
			int nx = light[x][y][i].first;
			int ny = light[x][y][i].second;
			if (light_check[nx][ny]) continue;
			light_check[nx][ny] = true;
			result++;
			//dx dy로 움직이는게 아니라 각 움직일 방향이 지정되어 있기 때문에 
			//범위 확인은 할 필요 없고 방문 확인만 하면됨
			if (can[nx][ny] == 1 && check[nx][ny] == 0) {
				q.push({ nx,ny });
			}
			
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (check[nx][ny]) continue;
			can[nx][ny] = true;
			if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
			//불이 꺼져있으면 갈 수 없음
			if (!light_check[nx][ny]) continue;
			//범위 넘어도 갈 수 없음
			check[nx][ny] = true;
			q.push({ nx,ny });
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		//x,y 위치에서 a,b로 이동 할 수 있다는 추가하라
		light[x][y].push_back({ a,b });
	}

	solve();

	cout<<result;

	return 0;
}