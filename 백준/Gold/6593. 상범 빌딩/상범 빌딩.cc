#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define endl "\n"
#define red 1
#define blue 2

using namespace std;
int l, r, c;
char building[31][31][31];
bool visit[31][31][31];

vector<int> result;

//시작, 끝 주소 저장
int sx, sy, sz, ex, ey, ez;

//z 높이

char a;

int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };

//g = goal
int solve(int gx, int gy, int gz) {

	queue<pair<pair<int, int>, pair<int,int>>> q;
	q.push({ {gx,gy},{gz,0 } });
	visit[gz][gx][gy] = true;
	while (!q.empty()) {

		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second.first;
		int count = q.front().second.second;
		q.pop();
		//골인 지점 도착했을시 return;
		if (x == ex && y == ey && z == ez) {
			return count;
		}
		
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (0 <= nx && nx < r && 0 <= ny && ny < c && 0 <= nz && nz < l && visit[nz][nx][ny] == false && (building[nz][nx][ny] == '.' || building[nz][nx][ny] == 'E')) {
				//q.push({ {gx,gy},{gz,0 } });
				visit[nz][nx][ny] = true;
				q.push({ {nx,ny},{nz,count + 1} });
			}
		}
	}

	return 0;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> l >> r >> c;
		memset(building, 0, sizeof(building));
		memset(visit, false, sizeof(visit));
		if (l == 0 && r == 0 && c == 0) {
			break;
		}
		else {
			//빌딩 입력
			for (int z = 0; z < l; z++) {
				for (int x = 0; x < r; x++) {
					string inputline;
					cin >> inputline;
					for (int y = 0; y < c; y++) {
						a = inputline[y];
						if (a == 'S') {
							sx = x;
							sy = y;
							sz = z;
						}
						else if (a == 'E') {
							ex = x;
							ey = y;
							ez = z;
						}
						building[z][x][y] = a;
					}
				}
			}

			//걸리는 시간 검사
			int flag = solve(sx,sy,sz);

			if (flag > 0) {
				result.push_back(flag);
			}
			else {
				result.push_back(0);
			}
		}
	}

	for (int i = 0; i < result.size(); i++) {
		if (result[i] != 0) {
			cout << "Escaped in "<< result[i] <<" minute(s)." << endl;
		}
		else {
			cout << "Trapped!" << endl;
		}
	}

	return 0;
}