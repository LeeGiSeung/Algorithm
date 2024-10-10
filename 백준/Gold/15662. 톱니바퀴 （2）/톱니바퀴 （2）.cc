#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int t, k, turn_gear, direction;

int gear[1001][8];
int c_gear[8];
bool check[1001];

void turn(int _gear, int _direction) {
	check[_gear] = true;
	//양 옆 검사하는건 index 2,6검사하면됨
	//서로 맞닿은 톱니의 극이 다르다면, B는 A가 회전한 방향과 반대방향으로 회전하게 된다
	//톱니바퀴의 범위는 1~t까지
	if (_gear - 1 >= 1 && !check[_gear - 1] ) {
		if (gear[_gear][6] != gear[_gear - 1][2]) {
			//회전한 방향의 반대로 회전
			turn(_gear - 1, -(_direction));
		}
	}
	if (_gear + 1 <= t && !check[_gear + 1]) {
		if (gear[_gear][2] != gear[_gear + 1][6]) {
			//회전한 방향의 반대로 회전
			turn(_gear + 1, -(_direction));
		}
	}

	// 방향이 1인 경우는 시계 방향이고, -1인 경우는 반시계 방향이다.

	//시계 방향
	if (_direction == 1) {
		for (int i = 0; i <= 6; i++) {
			c_gear[i + 1] = gear[_gear][i];
		}
		c_gear[0] = gear[_gear][7];
	}

	//반시계 방향
	if (_direction == -1) {
		for (int i = 6; i >= 0; i--) {
			c_gear[i] = gear[_gear][i + 1];
		}
		c_gear[7] = gear[_gear][0];
	}

	//c_gear 복사는 모든 바퀴가 돌고

	for (int i = 0; i <= 7; i++) {
		gear[_gear][i] = c_gear[i];
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	for (int i = 1; i <= t; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			// i번째 톱니바퀴 j번째 값
			// 12시방향부터 시계방향 순서대로 주어진다.
			// 2 6
			gear[i][j] = s[j] - '0';
		}
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		memset(check, false, sizeof(check));
		cin >> turn_gear >> direction;
		turn(turn_gear, direction);
	}

	int count = 0;
	for (int i = 0; i <= t; i++) {
		if (gear[i][0] == 1) {
			count++;
		}
	}

	cout << count;

	return 0;

}