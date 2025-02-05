#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int n, m;

bool check[500001][2];

void solve() {
	queue<int> q;
	q.push({n});
	int curtime = 1;
	if (n == m) {
		cout << 0;
		return;
	}
	while (!q.empty()) {
		m += curtime;

		//동생 위치가 500000넘으면 그냥 안되는거
		if (m > 500000) {
			cout << -1;
			break;
		}

		if (check[m][curtime % 2]) {
			cout << curtime;
			break;
		}

		int cir = q.size();

		for (int i = 0; i < cir; i++) {
			int x = q.front();
			q.pop();
			for (int nx : { x - 1, x + 1, x * 2}) {
				if (nx == m) {
					cout << curtime;
					return;
				}
				if (nx < 0 || nx > 500000) continue;
				if (check[nx][curtime % 2]) continue;
				check[nx][curtime % 2] = true;
				q.push(nx);
			}
		}
		curtime++;
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	//내위치, 시간, 동생 위치
	solve();

	return 0;
}