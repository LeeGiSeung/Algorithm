#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int result = 0;
char map[50][50];

char b;
char a;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//가장 긴 연속 행열 찾기
void _find() {

	//0~n-1번째 열 검사
	for (int i = 0; i < n; i++) {
		int count = 1;
		b = map[i][0];
		for (int j = 1; j < n; j++) {
			//만약 b랑 현재가 다를경우
			if (b != map[i][j]) {
				result = max(result, count);
				char q = map[i][j];
				b = map[i][j];
				count = 1;
			}
			else {
				count++;
			}
		}
		result = max(result, count);
	}

	//0~n-1번째 행 검사
	for (int i = 0; i < n; i++) {
		int count = 1;
		b = map[0][i];
		for (int j = 1; j < n; j++) {
			//만약 b랑 현재가 다를경우
			if (b != map[j][i]) {
				result = max(result, count);
				char q = map[i][j];
				b = map[j][i];
				count = 1;
			}
			else {
				count++;
			}
		}
		result = max(result, count);
	}

}

//1. 전환
void trans(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

		//바꾸고자 하는 곳 값 임시 저장
		a = map[nx][ny];
		map[nx][ny] = map[x][y];
		map[x][y] = a;

		//2. 가장 긴 연속 행열찾기
		_find();

		//원래 상태로 변환
		a = map[nx][ny];
		map[nx][ny] = map[x][y];
		map[x][y] = a;

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	_find();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//답이 이미 n과 같으면 더이상 탐색해도 답은 더 커질수 없음
			if (result == n) {
				cout << result;
				return 0;
			}
			//1. 전환
			trans(i, j);
		}
	}

	cout << result;

	return 0;
}