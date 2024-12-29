#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
#define INT_MAX 9999
int n, m;
int map[51][51];
bool check[51][51];
bool viruscheck[11];
bool virusmapcheck[51][51];
int zerocount = 0;
int result = 9999;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct DATA {
	int x;
	int y;
	int ti;
};
vector<pair<int, int>> virus;
//활성 바이러스가 비활성 바이러스가 있는 칸으로 가면 비활성 바이러스가 활성으로 변한다.
//처음에 모든 바이러스는 비활성화 상태이지만 m개의 바이러스를 처음에 활성화 상태로 변환 할 수 있다.
//그뒤로 지나다니는 동안 만약 비활성화 바이러스를 만나게 되면 해당 바이러스를 활성화 상태로 변환한다.

void solve() {
	
	queue<DATA> q;
	int cur_ti = 0;
	int cur_zero = 0;
	memset(check, false, sizeof(check));

	for (int i = 0; i < virus.size(); i++) {
		if (viruscheck[i]) {
			int x = virus[i].first;
			int y = virus[i].second;
			q.push({ x,y,0 });
			check[x][y] = true;
		}
	}

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int ti = q.front().ti;
		q.pop();
			
		if (map[x][y] == 0) {
			cur_zero++;
		}

		if (cur_zero == zerocount) {
			cur_ti = ti;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			//범위에 맞지 않으면 안됨
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			//벽이면 안됨
			if (map[nx][ny] == 1) continue;
			//이미 방문했던 곳이여도 안됨
			if (check[nx][ny]) continue;

			check[nx][ny] = true;
			q.push({ nx, ny,ti + 1 });

		}

	}

	//만약 0을 전부 감염시켰으면
	if (cur_zero == zerocount) {
		result = min(result, cur_ti);
	}

	return;

}

void spread_virus(int _index ,int _virus_count) {
	//정해놓은 바이러스와 같아지면
	if (_virus_count == m) {
		solve();
		return;
	}
	for (int i = _index; i < virus.size(); i++) {
		if (!viruscheck[i]) {
			viruscheck[i] = true;
			spread_virus(i + 1 ,_virus_count + 1);
			viruscheck[i] = false;
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			map[i][j] = a;
			//0이면 바이러스를 놓을 수 있는 자리임
			if (a == 0) {
				zerocount++;
			}
			//2이면 바이러스가 비활성화 돼있는 자리임
			else if (a == 2) {
				virus.push_back({ i,j });
			}
			//1이면 그냥 벽임
		}
	}
	
	spread_virus(0,0);

	if (result == INT_MAX) {
		cout << -1;
	}
	else {
		cout << result;
	}


	return 0;
}