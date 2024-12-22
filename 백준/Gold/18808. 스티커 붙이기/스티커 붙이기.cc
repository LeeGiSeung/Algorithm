#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n = 0;
int m = 0;
int k = 0;
int NoteBook[40][40];
int sticker[10][10];
int copysticker[10][10];
int r, c;

bool canstiker(int x, int y) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			//현재 스티커를 붙일 수 있는데 이미 노트북에 스티커가 붙어 있을 경우
			if (NoteBook[i + x][j + y] == 1 && sticker[i][j] == 1) {
				return false;
			}
		}
	}
	//스티커를 붙일 수 있는 경우
	return true;
}

void paste(int x, int y) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			//현재 스티커를 붙일 수 있는데 이미 노트북에 스티커가 붙어 있을 경우
			if (sticker[i][j] == 1) {
				NoteBook[i + x][j + y] = 1;
			}
		}
	}
}

void rotate() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			copysticker[j][r - 1 - i] = sticker[i][j];
		}
	}
	// r값과 c값을 회전했으면 크기도 회전한 만큼 바껴야함
	int tmp = c;
	c = r;
	r = tmp;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			 sticker[i][j] = copysticker[i][j];
		}
	}
}

void solve() {
	//4번 회전
	for (int rotation = 0; rotation < 4; rotation++) {
		for (int i = 0; i + r <= n; i++) {
			for (int j = 0; j + c <= m; j++) {
				if(canstiker(i, j)) {
					paste(i, j);
					//스티커를 붙였으니 더 이상 할 필요가 없음
					return;
				}
			}
		}
		//회전
		rotate();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	while (k--) {
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> sticker[i][j];
			}
		}
		solve();
		memset(sticker, false, sizeof(sticker));
		memset(copysticker, false, sizeof(copysticker));
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (NoteBook[i][j] == 1) {
				result++;
			}
		}
	}

	cout << result;

	return 0;
}