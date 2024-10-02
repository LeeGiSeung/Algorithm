#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 1000000000


struct DATA {
	int start;
	int end;
	int distance;
};
vector<DATA> v;
long long dist[501];
int flag = 0;
int n, m;

void dij(int x) {
	
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}

	dist[x] = 0;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < v.size(); j++) {
			int start = v[j].start;
			int end = v[j].end;
			int distance = v[j].distance;
			if (dist[start] == INF) continue;
			if (dist[end] > dist[start] + distance) dist[end] = distance + dist[start];
		}
	}

	for (int i = 0; i < v.size(); i++) {
		int start = v[i].start;
		int end = v[i].end;
		int distance = v[i].distance;
		if (dist[start] == INF) continue;
		if (dist[end] > dist[start] + distance) {
			flag = 1;
			break;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//1번 도시에서 출발해서 나머지 도시로 가는 가장 빠른 시간을 구하는 프로그램을 작성하시오.

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}

	dij(1);
	
	if (flag == 1) {
		cout << -1;
		return 0;
	}

	for (int i = 2; i <= n; i++) {
		
		if (dist[i] == INF) {
			cout << -1;
		}
		else {
			cout << dist[i];
		}
		cout << "\n";
	}

	return 0;
}