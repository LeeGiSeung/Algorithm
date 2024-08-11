#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1005
#define LL long long
#define INF 2e9

using namespace std;
int N, M;
vector<pair<int, int> > Vec[MAX];
bool visited[MAX];

void init() {
	for (int i = 0; i < MAX; i++) {
		visited[i] = false;
	}
}

int BFS(int X, int Y) {
	init();
	queue<pair<int, int> > Q;
	visited[X] = true;
	Q.push(make_pair(X, 0));

	while (!Q.empty()) {
		int CurX = Q.front().first;
		int CurCost = Q.front().second;
		Q.pop();

		if (CurX == Y) {
			return CurCost;
		}

		for (int i = 0; i < Vec[CurX].size(); i++) {
			int nextX = Vec[CurX][i].first;
			int nextCost = Vec[CurX][i].second;
			if (!visited[nextX]) {
				visited[nextX] = true;
				Q.push(make_pair(nextX, CurCost + nextCost));
			}
		}
	};
}

int main() {
	FIRST
	cin >> N >> M;
	for (int i = 0; i < (N - 1); i++) {
		int X, Y, D;
		cin >> X >> Y >> D;
		Vec[X].push_back(make_pair(Y, D));
		Vec[Y].push_back(make_pair(X, D));
	}
	for (int i = 0; i < M; i++) {
		int X, Y;
		cin >> X >> Y;
		cout << BFS(X, Y) << "\n";
	}

	return 0;
}