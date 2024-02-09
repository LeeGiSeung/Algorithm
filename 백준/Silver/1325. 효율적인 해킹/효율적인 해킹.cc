#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
int N, M;
const int MAX = 10001;
vector<int> map[MAX];
bool visited[MAX];
vector<pair<int, int>> v;
int hacked = 1; 

void BFS(int v) {

	visited[v] = true;
	deque<int> q;
	q.push_back(v);

	while (!q.empty()) {
		int f = q.front();
		q.pop_front();
		for (int w = 0; w < map[f].size(); w++) {
			int vi = map[f][w];

			if (visited[vi] == 0) {
				visited[vi] = true;
				q.push_back(vi);
				hacked++;
			}
		}
	}
}

void resetVisit() {
	for (int i = 0; i <= N; i++) {
		visited[i] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        map[b].push_back(a);
    }

	for (int i = 1; i <= N; i++) {
		BFS(i);
		resetVisit();
		v.push_back(make_pair(i, hacked ));
		hacked = 1;

	}

	int maxHack = -1;

	for (int i = 0; i < v.size(); i++) {
		if (v[i].second > maxHack) {
			maxHack = v[i].second;
		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (v[i].second == maxHack) {
			cout << v[i].first << " ";
		}
	}

}

