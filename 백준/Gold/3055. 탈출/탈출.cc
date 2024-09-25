#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
int beaver_x;
int beaver_y;
int gosum_x;
int gosum_y;
int water_x = -1;
int water_y = -1;

int result = -1;

int watermap[51][51];
char map[51][51];
bool check[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<pair<int, int>> water;
struct DATA {
	int x;
	int y;
	int count;
};

void move_water() {
	memset(check, false, sizeof(check));
	queue<DATA> q;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '*') {
				q.push({ i,j,0 });
				check[i][j] = true;
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int count = q.front().count;
		q.pop();

		watermap[x][y] = count;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
		
			if (0 <= nx && nx < n && 0 <= ny && ny < m && map[nx][ny] == '.') {
				if (check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push({ nx,ny,count + 1 });
				}
			}
		}
	}
}

void move_gosum(int x, int y) {
	memset(check, false, sizeof(check));
	queue<DATA> q;
	q.push({ x,y,0 });
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int count = q.front().count;
		q.pop();

		//cout << "고슴 이동 " << x << " " << y << " " << count << endl;

		if (x == beaver_x && y == beaver_y) {
			//cout << "정답" << endl;
			result = count;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && map[nx][ny] !='X') {
				if (count + 1 < watermap[nx][ny]) {
					if (check[nx][ny] == false) {
						check[nx][ny] = true;
						q.push({ nx,ny,count + 1 });
					}
					else {
						//cout << "이미 방문함" << endl;
					}
				}
				else {
					//cout << "count가 큼" << endl;
				}	
			}
		}
	}
}

void answer() {
	if (result == -1) {
		cout << "KAKTUS";
	}
	else {
		cout << result;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//고슴도치 위치, 비버 굴 알아야함
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			map[i][j] = s[j];
			if (s[j] == 'S') {
				gosum_x = i;
				gosum_y = j;
			}
			else if (s[j] == 'D') {
				beaver_x = i;
				beaver_y = j;
			}
		}
	}

	//cout << water_x << " " << water_y << endl;
	//물 이동
	memset(watermap, 9999999, sizeof(watermap));

	move_water();
	//고슴도치 이동
	move_gosum(gosum_x, gosum_y);
	//정답
	answer();

	return 0;
}