#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int r, c;
string inputmove;
char map[1001][1001];
char resultmap[1001][1001];
bool check[1001][1001];
//위 아래 왼쪽 오른쪽
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void ward(int _x, int _y) {

	queue<pair<int, int>> q;
	q.push({ _x,_y });
	//영역 문자
	int cur_char = map[_x][_y];
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		resultmap[x][y] = '.';

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < r && 0 <= ny && ny < c) {
				if (!check[nx][ny]) {
					if (map[nx][ny] == cur_char) {
						check[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}

	}
}

void ch(int _x, int _y) {
	int x = _x;
	int y = _y;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < r && 0 <= ny && ny < c) {
			resultmap[nx][ny] = '.';
		}
	}
}

void solve(int _x, int _y){
	int x = _x;
	int y = _y;
	for (int i = 0; i < inputmove.size(); i++) {
		char cur_move = inputmove[i];
		//와드 설치
		if (cur_move == 'W') {
			ward(x, y);
		}
		else {
			//이동할때는 check 확인 하면 안됨
			//위로 이동
			if (cur_move == 'U') {
				x += dx[0];
				y += dy[0];
			}
			else if (cur_move == 'D') {
				x += dx[1];
				y += dy[1];
			}
			else if (cur_move == 'L') {
				x += dx[2];
				y += dy[2];
			}
			else if (cur_move == 'R') {
				x += dx[3];
				y += dy[3];
			}
		}
	}
	resultmap[x][y] = '.';
	ch(x, y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(resultmap, '#', sizeof(resultmap));
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			map[i][j] = s[j];
		}
	}

	int a, b;
	cin >> a >> b;
	cin >> inputmove;

	solve(a - 1, b - 1);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << resultmap[i][j];
		}
		cout << "\n";
	}

	return 0;
}