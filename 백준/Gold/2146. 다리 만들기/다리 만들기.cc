#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct BRIDGE_DATA {
	int x;
	int y;
	int cur;
};
int n;

int map[101][101];
int bridge[101][101];
bool check[101][101];
int result = 9999;
int island = 2;
vector<pair<int, int>> v[10001];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void SetMap(int _x, int _y, int island) {
	queue<pair<int, int>> q;
	q.push({ _x,_y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		map[x][y] = island;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (check[nx][ny] == true) continue;
			//이어져 있는 땅이면
			if (map[nx][ny] == 1) {
				check[nx][ny] = true;
				q.push({ nx,ny });
			}
			//섬의 가장자리이면
			else if (map[nx][ny] == 0) {
				v[island].push_back({ x,y });
			}

		}
	}
}

void find_bridge(vector<pair<int,int>> v, int _island) {
	queue<BRIDGE_DATA> q;

	for (int i = 0; i < v.size(); i++) {
		q.push({ v[i].first, v[i].second, 0 });
	}

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cur = q.front().cur;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			//다리를 놓을 수 있는 땅
			if (map[nx][ny] == 0 && bridge[nx][ny] > cur + 1) {
				bridge[nx][ny] = cur + 1;
				q.push({ nx,ny,cur + 1 });
			}
			else if (map[nx][ny] != 0 && map[nx][ny] != _island) {
				//다른 대륙이면 다리를 더 안놓아도 됨
				result = min(result, cur);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	//각 섬이 끝 부분을 알아야함
	//각 섬이 다른 섬이라는 것을 알아야 함
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				SetMap(i, j, island);
				island++;
			}
		}
	}
	memset(bridge, 100, sizeof(bridge));
	for (int i = 2; i <= island; i++) {
		find_bridge(v[i], i);
	}

	cout << result;

	return 0;
}