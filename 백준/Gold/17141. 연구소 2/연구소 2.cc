#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
struct DATA {
	int width;
	int height;
	int ti;
};
int n, m;
int map[51][51];
vector<pair<int, int>> v;
bool TwoCheck[10];
bool check[51][51];
int zeroCount;
queue<DATA> q;
vector<pair<int, int>> cv;

int result = 5000;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int solve() {
	//현재 감염시킨 횟수
	int cur_per = 0;
	int cur_ti = 0;
	int done = zeroCount;
	memset(check, false, sizeof(check));
	for (int i = 0; i < v.size(); i++) {
		if (TwoCheck[i]) {
			q.push({ v[i].first,v[i].second,0 });
			check[v[i].first][v[i].second] = true;
		}
	}
	while (!q.empty()) {
		int width = q.front().width;
		int height = q.front().height;
		int ti = q.front().ti;
		q.pop();

		done--;
		cur_ti = max(ti, cur_ti);

		for (int i = 0; i < 4; i++) {
			int nwidth = width + dx[i];
			int nheight = height + dy[i];
			//범위를 넘으면 가지 않음
			if (0 > nwidth || nwidth >= n || 0 > nheight || nheight >= n) continue;
			//방문했던 곳이면 가지 않음
			if (check[nwidth][nheight]) continue;
			//벽이면 가지 않음
			if (map[nwidth][nheight] == 1) continue;

			check[nwidth][nheight] = true;
			q.push({ nwidth,nheight,ti + 1 });
		}
	}

	//감염을 전부 못 시켰으면
	if (done == 0){
		return cur_ti;
	}
	else {
		return 9999;
	}
}

void findlab(int _LabCount, int curLab) {
	if (_LabCount == m) {
		result = min(result, solve());
		return;
	}
	for (int i = curLab; i < v.size(); i++) {
		if (TwoCheck[i]) continue;
		TwoCheck[i] = true;
		findlab(_LabCount + 1, curLab + 1);
		TwoCheck[i] = false;
	
	}
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
			//감염 될 수 있는 자리
			if (a != 1) {
				zeroCount++;
			}
			//바이러스를 놓을 수 있는 자리이면
			if (a == 2) {
				v.push_back({ i,j });
			}
		}
	}

	findlab(0, 0);

	if (result == 5000)
	{
		cout << -1;
	}
	else cout << result;	
	return 0;
}