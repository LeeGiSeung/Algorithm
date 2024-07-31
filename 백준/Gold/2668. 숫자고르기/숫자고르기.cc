#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int n,a;


bool visit[101] = { false };
int v[101];
vector<int> result;

void dfs(int start, int end) {
	// 만약 첫 번째 줄 값하고 두번째가 같으면 결과에 넣음
	if (v[start] == end) {
		result.push_back(start);
		return;
	}
	else 
	{
		if (visit[start] == false) {
			visit[start] = true;
			dfs(v[start], end);
		}
	}
	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a;
		v[i] = a;
	}

	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		// 첫 번째 줄 값하고 두번째 줄 값
		dfs(i, i);
	}

	sort(result.begin(), result.end());

	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}

	return 0;
}
