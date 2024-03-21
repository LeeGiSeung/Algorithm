#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>
#include <cstring>

using namespace std;
int n, result = 0;
int house[18][18];

int turn = 0;

void pi(int x, int y, int turn, int l) {
	if (x == n - 1 && y == n - 1) {
		result++;
		return;
	}
	//가로
	if (house[x][y + 1] == 0 && x < n && y < n && l == 0) {
		pi(x, y + 1, 0, 0);
	}
	//세로 -> 세로
	if (house[x + 1][y] == 0 && x + 1 < n && y < n && l == 1) {
		pi(x + 1, y, 0, 1);
	}
	//대각선 -> 세로
	if (house[x + 1][y] == 0 && x + 1 < n && y < n && turn == 1) {
		pi(x + 1, y, 0, 1);
	}
	//대각선
	if (house[x + 1][y + 1] == 0 && house[x][y + 1] == 0 && house[x + 1][y] == 0 && x + 1 < n && y + 1 < n) {
		pi(x + 1, y + 1, 1, 0);
	}

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> house[i][j];
		}
	}
	pi(0, 1, 0, 0);

	cout << result;

	return 0;

}