#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

struct DATA {
	int x;
	int y;
	int move;
};

int	castlemove[10];

int n, m, p;
int map[1001][1001];
queue<pair<int, int>> v[11];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int result[11];
bool check[1001][1001];
void solve() {
	while (true) {
		bool movecastle = false;
		for (int i = 1; i <= p; i++) {
			queue<DATA> q;


			while (!v[i].empty()) {
				q.push({ v[i].front().first,v[i].front().second, 0});
				check[v[i].front().first][v[i].front().second] = true;
				v[i].pop();

			}

			while (!q.empty()) {
				int x = q.front().x;
				int y = q.front().y;
				int move = q.front().move;
				q.pop();



				//i가 현재 성의 번호임
				//움직일 만큼 다 움직였으면 더이상 움직이지 않음
				if (move == castlemove[i]) {
					v[i].push({ x,y });
				}

				else {
					for (int z = 0; z < 4; z++) {
						int nx = x + dx[z];
						int ny = y + dy[z];

						//범위 안에 있고
						if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
							//아직 방문하지 않았고
							if (!check[nx][ny]) {
								//빈 구역일때
								if (map[nx][ny] == '.') {
									check[nx][ny] = true;
									map[nx][ny] = i;
									movecastle = true;
									q.push({ nx,ny, move + 1 });
								}
							}
						}
					}
				}

			}
		}
		if (!movecastle) break;
	}
	return;
}

int main()	
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> p;

	for (int i = 1; i <= p; i++) {
		cin >> castlemove[i];
	}

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			char a = s[j];
			//빈공간도 아니고 벽도 아니면 성의 위치이다.
			if (a != '.' && a != '#') {
				v[a - '0'].push({i,j + 1});
				map[i][j + 1] = a - '0';
			}
			else {
				map[i][j + 1] = a;
			}

		}		
	}
	int a = 0;
	solve();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] != '#' && map[i][j] != '.') {
				result[map[i][j]]++;
			}
		}
	}

	for (int i = 1; i <= p; i++) {
		cout << result[i] << " ";
	}

	return 0;
}