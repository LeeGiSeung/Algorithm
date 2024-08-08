#include <iostream>
#include <cstring>
#include <climits>
#include <queue>

using namespace std;

int map[126][126];
int dp[126][126];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int n;

int solve() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	int result = INT_MAX;

	dp[0][0] = map[0][0];

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == n - 1 && y == n - 1) {
			if (result > dp[x][y]) {
				result = dp[x][y];
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			//영역 안에 있고
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				//cout << nx <<" "<<ny<<" 검사" << endl;
				//cout << dp[x][y] + map[nx][ny] << " " << dp[nx][ny] << endl;
				// 다음 동굴이 현재 값에 nx ny더한것보다 작은 경우 -> 링크가 잃을 수 밖에 없는 최소금액을 구할 수 있음
				if (dp[x][y] + map[nx][ny] < dp[nx][ny]) {
					dp[nx][ny] = dp[x][y] + map[nx][ny];
					q.push({ nx,ny });
				}
			}
		}

	}

	return result;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count = 0;

	while (true) {

		count++;

		cin >> n;

		if (n == 0) {
			break;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = 210000000;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		int k = solve();

		cout << "Problem " << count << ": " << k << "\n";

		memset(map, 0, sizeof(map));

	}

	return 0;
}