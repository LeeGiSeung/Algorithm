#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct DATA {
	int cur;
	int floor;
};
vector<int> v[51];
vector<int> result[51];
int n = 0;
int a, b;
bool check[51];

int minfloor = 9999999999;

void solve(int a) {
	memset(check, false, sizeof(check));
	queue<DATA> q;
	int maxfloor = 0;
	q.push({a, 0});

	check[a] = true;

	while (!q.empty()) {
		int cur = q.front().cur;
		int floor = q.front().floor;
		q.pop();

		//cout << cur << " " << floor << endl;

		maxfloor = max(maxfloor, floor);

		for (int i = 0; i < v[cur].size(); i++) {
			if (check[v[cur][i]] == false) {
				check[v[cur][i]] = true;
				q.push({ v[cur][i], floor + 1 });
			}
		}
	}
	result[maxfloor].push_back(a);
	minfloor = min(maxfloor, minfloor);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	while (true) {
		cin >> a >> b;
		if (a == -1 && b == -1) {
			break;
		}
		v[a].push_back(b);
		v[b].push_back(a);
	}

	//1~n번째 사람까지의 회장 후보 검사
	for (int i = 1; i <= n; i++) {
		if (v[i].size() == 0) continue;
		solve(i);
	}

	cout << minfloor << " " << result[minfloor].size() << "\n";
	for (int i = 0; i < result[minfloor].size(); i++) {
		cout << result[minfloor][i] << " ";
	}

	return 0;
}