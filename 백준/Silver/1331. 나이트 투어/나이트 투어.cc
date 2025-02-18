#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int dx[8] = { -1,-2,-2,-1,1,2,2,1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };

int past_x;
int past_y;

int start_x;
int start_y;

string s;

bool check[8][8];

int main() {

	cin >> s;

	int past_x = s[0] - 'A' + 1;
	int past_y = s[1] - '0';

	start_x = past_x;
	start_y = past_y;

	check[past_x][past_y] = true;

	for (int i = 0; i < 35; i++) {

		bool flag = false;

		cin >> s;

		int x = s[0] - 'A' + 1;
		int y = s[1] - '0';

		for (int i = 0; i < 8; i++) {
			int nx = past_x + dx[i];
			int ny = past_y + dy[i];

			//이전 위치에서 나이트 위치로 이동했을때 올 수 있는 위치인 경우
			if (nx == x && ny == y && !check[x][y]) {
				flag = true;
				check[x][y] = true;
				past_x = x;
				past_y = y;
				break;
			}
		}

		if (flag == false) {
			cout << "Invalid";
			return 0;
		}
	}

	bool flag = false;

	for (int i = 0; i < 8; i++) {
		int nx = past_x + dx[i];
		int ny = past_y + dy[i];

		//이전 위치에서 나이트 위치로 이동했을때 올 수 있는 위치인 경우
		if (nx == start_x && ny == start_y) {
			flag = true;
			break;
		}
	}

	if (flag == false) {
		cout << "Invalid";
	}
	else {
		cout << "Valid";
	}

	return 0;
}