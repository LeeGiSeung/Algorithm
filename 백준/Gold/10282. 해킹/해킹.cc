#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int t;
int n, d, c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	while (t--) {

		cin >> n >> d >> c;
		vector<pair<int, int>> v[10001];
		//c가 해킹 당한 컴퓨터임

		for (int i = 0; i < d; i++) {
			int a, b, s;
			//컴퓨터 a가 컴퓨터 b를 의존하며, 컴퓨터 b가 감염되면 s초 후 컴퓨터 a도 감염됨을 뜻한다.
			cin >> a >> b >> s;
			v[b].push_back({a,s});
		}

		int dist[10001];

		for (int i = 1; i <= n; i++) {
			dist[i] = 10000001;
		}

		dist[c] = 0;

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({ c,0 });

		while (!pq.empty()) {
			int cur = pq.top().first;
			int ti = pq.top().second;
			pq.pop();

			for (int i = 0; i < v[cur].size(); i++) {
				int next_point = v[cur][i].first;
				int next_ti = ti + v[cur][i].second;

				//cout <<next_point<<" "<< next_ti << " " << dist[next_point] << "\n";
				if (dist[next_point] > next_ti) {
					dist[next_point] = next_ti;
					pq.push({ next_point,next_ti });
				}
			}
		}

		int result = 0;
		int count = 0;

		for (int i = 1; i <= n; i++) {
			if (dist[i] != 10000001) {
				result = max(result, dist[i]);
				count++;
			}
		}

		cout << count << " " << result << "\n";

	}

	return 0;
}