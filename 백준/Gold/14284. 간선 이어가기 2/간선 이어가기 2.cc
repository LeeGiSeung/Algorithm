#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

#define INF 10000

using namespace std;
vector<pair<int,int>> v[5000];
int check[5000];
int n, m, s, t;

int result = 0;

void dij(int s, int t) {
	priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	memset(check, INF, sizeof(check));

	pq.push({ 0,s });

	while (!pq.empty()) {
		int distance = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		//cout << cur << " " << distance << endl;

		check[cur] = distance;

		if (cur == t) {
			break;
		}

		for (int i = 0; i < v[cur].size(); i++) {
			int next_cur = v[cur][i].first;
			int next_distance = v[cur][i].second + distance;
			if (check[next_cur] > next_distance) {
				pq.push({ next_distance,next_cur });
			}
		}

	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	cin >> s >> t;

	dij(s, t);

	//for (int i = 1; i <= n; i++) {
	//	if (check[i] != INF) {
	//		result += check[i];
	//	}
	//}

	cout << check[t];

	return 0;
}