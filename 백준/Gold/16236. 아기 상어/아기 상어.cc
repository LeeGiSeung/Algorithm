#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct DATA {
	int x = 0;
	int y = 0;
	int ti = 0;
};
DATA BABY_SHARK;

int result = 0;
int eat = 0;
int map[21][21];

int n;

int BabySize = 2;
//상 좌 하 우
//가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.
//상 좌 하 우
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
bool check[21][21];

//아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가한다.예를 들어, 
//크기가 2인 아기 상어는 물고기를 2마리 먹으면 크기가 3이 된다.

//거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.

//아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다.
//아기 상어는 자신의 크기보다 작은 물고기만 먹을 수 있다.

void bfs(int x, int y) {

	//flag가 0이면 먹을 상어를 찾지 못한거
	

	//맨 처음에는 아기상어 위치를 지정해주고 나중에는 자동 업데이트 해야함
	int cur_x = x;
	int cur_y = y;

	//1. 자신이 먹을 수 있는 물고기의 위치를 찾음
	while (true) {

		memset(check, false, sizeof(check));
		check[cur_x][cur_y] = true;

		queue<DATA> q;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

		int dist = 0;
		q.push({ cur_x, cur_y,0 });

		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			int ti = q.front().ti;
			//cout << x << " " << y << " " << ti << endl;;
			q.pop();

			if (map[x][y] < BabySize && map[x][y] > 0) {
				if (!dist) {
					dist = ti;
					pq.push({ x,y });
				}
				else if (dist == ti) {
					pq.push({ x,y });
				}
			}
			else {
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					//범위안, 방문한적 x, 갈 수 있는 위치
					if (0 <= nx && nx < n && 0 <= ny && ny < n && !check[nx][ny] && BabySize >= map[nx][ny]) {
						check[nx][ny] = true;
						q.push({ nx,ny, ti + 1 });
					}
				}
			}
		}

		//만약 물고기를 찾을 수 없으면 return
		if (pq.empty()) return;

		//2. 그 물고기로 이동하면서 시간 업데이트
		cur_x = pq.top().first;
		cur_y = pq.top().second;
		result += dist;

		map[cur_x][cur_y] = 0;
		eat += 1;
		if (BabySize == eat) {
			BabySize += 1;
			eat = 0;
		}

	}

	return;

}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			//9의 위치가 아기상어 위치
			if (map[i][j] == 9) {
				BABY_SHARK.x = i;
				BABY_SHARK.y = j;
				map[i][j] = 0;
			}
		}
	}
	
	bfs(BABY_SHARK.x, BABY_SHARK.y);

	cout << result;

	return 0;
}