#include <iostream>
#include <queue>
#include <vector>
#include <queue>

using namespace std;

struct BEAD {
	int RX;
	int RY;
	int BX;
	int BY;
	int count;
};

int n, m;

char map[10][10];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int blue_move(int& x, int& y, int dir) {
	int count = 0;

	//벽이 아닐때 까지
	while (map[x + dx[dir]][y + dy[dir]] != '#') {
		count++;
		x = x + dx[dir];
		y = y + dy[dir];
		if (map[x][y] == 'O') {
			return -1;
		}
	}
	return count;
}

int red_move(int& x, int& y, int dir) {
	int count = 0;

	//벽이 아닐때 까지
	while (map[x + dx[dir]][y + dy[dir]] != '#') {
		count++;
		x = x + dx[dir];
		y = y + dy[dir];
		if (map[x][y] == 'O') return count;

	}
	return count;

}

int bfs(int rx, int ry, int bx, int by) {
	int check[10][10][10][10] = { false };
	queue<BEAD> q;
	q.push({ rx, ry, bx, by, 0 });

	while (!q.empty()) {
		int rx = q.front().RX;
		int ry = q.front().RY;
		int bx = q.front().BX;
		int by = q.front().BY;
		int count = q.front().count;
		q.pop();

		if (map[rx][ry] == 'O' && count > 10) {
			return 0;
		}

		if (map[rx][ry] == 'O' && count <= 10) {
			return 1;
		}

		if (count > 10) break;

		for (int i = 0; i < 4; i++) {
			int cur_rx = rx;
			int cur_ry = ry;
			int cur_bx = bx;
			int cur_by = by;

			int blueCount = blue_move(cur_bx, cur_by,i);
			int redCount = red_move(cur_rx, cur_ry,i);

			//파랑 구슬이 들어갔으면 할 가치가 없음
			if (blueCount == -1) continue;
			//이미 방문했던 구슬 위치면 할 가치가 없음
			if (check[cur_rx][cur_ry][cur_bx][cur_by] == true) continue;

			if (cur_rx == cur_bx && cur_ry == cur_by) {
				if (blueCount > redCount) {
					cur_bx -= dx[i];
					cur_by -= dy[i];
				}
				else if (blueCount < redCount) {
					cur_rx -= dx[i];
					cur_ry -= dy[i];
				}
			}

			check[cur_rx][cur_ry][cur_bx][cur_by] = true;
			q.push({ cur_rx,cur_ry,cur_bx,cur_by,count + 1 });

		}
	}

	//그냥 못가는 거일때
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int rx = 0;
	int ry = 0;
	int bx = 0;
	int by = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			map[i][j] = s[j];
			if (s[j] == 'R') {
				rx = i;
				ry = j;
			}
			else if (s[j] == 'B') {
				bx = i;
				by = j;
			}
		}
	}

	int result = bfs(rx,ry,bx,by);

	cout << result;

	return 0;
}