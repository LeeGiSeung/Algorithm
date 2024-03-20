#include <iostream>

using namespace std;

int n, arr[17][17], xmove[3] = { 0, 1, 1 }, ymove[3] = { 1, 0, 1 };
int record[17][17], answer;

void DFS(int x, int y, int direction) {
	if (x == n - 1 && y == n - 1) {
		answer++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (direction == 0 && i == 1)
			continue;
		else if (direction == 1 && i == 0)
			continue;
		else {
			int nx = x + xmove[i];
			int ny = y + ymove[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (i == 0 || i == 1) {
					if (arr[nx][ny] == 0 && !record[nx][ny]) {
						record[nx][ny] = true;
						DFS(nx, ny, i);
						record[nx][ny] = false;
					}
				}
				else {
					if (arr[nx][ny] == 0 && arr[nx-1][ny] == 0 && arr[nx][ny-1] == 0 && !record[nx][ny]) {
						record[nx][ny] = true;
						DFS(nx, ny, i);
						record[nx][ny] = false;
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	DFS(0, 1, 0);

	cout << answer;
}
