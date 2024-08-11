#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n,m;
vector<pair<int, int>> v[1005];
bool visit[1005] = { false };

int solve(int s, int e) {
	visit[s] = true;
	queue<pair<int,int>> q;
	int distance = 0;
	q.push({ s,0 });
	while (!q.empty()) {
		s = q.front().first;
		distance = q.front().second;
		q.pop();
		
		if (s == e) {
			return distance;
		}

		for (int i = 0; i < v[s].size(); i++) {
			if (visit[v[s][i].first] == false) {
				visit[v[s][i].first] = true;
				q.push({ v[s][i].first,distance + v[s][i].second });
			}
		}

	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;

	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));

	}

	for (int i = 0; i < m; i++) {
		memset(visit, false, sizeof(visit));
		int a, b;
		cin >> a >> b;
		cout<<solve(a, b)<<"\n";
	}



	return 0;
}