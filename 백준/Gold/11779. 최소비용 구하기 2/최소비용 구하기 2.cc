#include <iostream>
#include <queue>
#include <vector>
#include <stack>

#define INF 987654321

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
int N, M, from, to, weight, start, target;
vector<pii> v[1001];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int dist[1001], route[1001] ;
stack<int> st;

int dijkstra(int startX, int target) {
	dist[startX] = 0;
	pq.push(make_pair(dist[startX], startX));

	while (!pq.empty()) {
		int dis = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (x == target)
			return dist[target];


		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			int weight = v[x][i].second;

			if (dist[nx] > dis + weight) {
				dist[nx] = dis + weight;
				pq.push(make_pair(dist[nx], nx));
				route[nx] = x; // 경로를 저장해준다.
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> weight;
		v[from].push_back(make_pair(to, weight));
	}
	cin >> start >> target;

	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}

	cout<<dijkstra(start, target)<<"\n";
	
	for (int i = target; i != start; i = route[i]) // 경로 역추적 5 4 1 순서
		st.push(i);
	st.push(start);

	cout << st.size() << "\n";
	while (!st.empty()) {
		cout << st.top() << " "; // 다시 역순 출력
		st.pop();
	}

}