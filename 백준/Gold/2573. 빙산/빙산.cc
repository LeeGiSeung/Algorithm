#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include<algorithm>

#define endl "\n"

using namespace std;
int n, m;
int ice[300][300] = { 0 };
int copy_ice[300][300];
int visit[300][300] = { false };
int year = 0;
bool check = false;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs(int x, int y) {

	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[x][y] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (copy_ice[nx][ny] != 0) {
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && visit[nx][ny] == false) {
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
}

void copy_ice_fun(int x[300][300], int y[300][300]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			x[i][j] = y[i][j];
		}
	}
}

void ice_check() {
	check = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (ice[i][j] != 0){
				//cout << i << " " << j << "는 0이 아닙니다." << endl;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (ice[nx][ny] == 0 && nx >= 0 && nx < n && ny >= 0 && ny < m) {
						//cout << i << " " << j << "에서 " <<nx<<" "<<ny<<"의 좌표값이 0이여서 -1을 합니다."<< endl;
						if (copy_ice[i][j] - 1 >= 0) {
							copy_ice[i][j] -= 1;
						}
					}
				}

			}
		}
	}
}

int main()
{
	cin >> n >> m;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			ice[i][j] = a;
			if (a == 0) {
				check = true;
			}
		}
	}

	if (check == false) {
		cout << 0 << endl;
		return 0;
	}

	else {
		while (true) {
			int island = 0;
			year++;
			copy_ice_fun(copy_ice,ice);
			ice_check();

			
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (copy_ice[i][j] != 0 && visit[i][j] == false) {
						bfs(i, j);
						island++;
					}
				}
			}
			if (island >= 2) {
				cout << year;
				break;
			}

			if (island == 0) {
				cout << 0 << endl;
				break;
			}

			copy_ice_fun(ice, copy_ice);

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					visit[i][j] = false;
				}
			}

		}
	}

	return 0;
}
