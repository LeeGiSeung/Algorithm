#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int V;
const int MAX = 100001;
vector <pair<int, int>>v[MAX];
int visited[MAX] = { 0, };
int maxdist = 0;
int maxnode;

void input() {
	cin >> V;
	for (int i = 0; i < V; i++) {
		int num, n1, n2;
		cin >> num;
		cin >> n1;
		while (n1 != -1) {
			cin >> n2;
			v[num].push_back({ n1,n2 });
			v[n1].push_back({ num,n2 });
			cin >> n1;
		}
	}
}

void dfs(int i,int dist) {
	if (visited[i]) //방문한거면 다시방문X
		return;
	if (maxdist < dist) { //갱신해나가는과정
		maxdist = dist;
		maxnode = i;
	}
	visited[i] = true;
	for (int j = 0; j < v[i].size(); j++) {
		int ni = v[i][j].first;
		int nd = v[i][j].second;
		dfs(ni, nd + dist);
	}
}

int main() {
	input();
	dfs(1,0);//1정점에서 시작한다. distance=0으로 들어갈것 maxnode를 구해야된다.
	memset(visited, false, sizeof(visited));
	maxdist = 0;
	dfs(maxnode, 0);//찾은 그 노드에서 가장먼것을 찾는다.
	cout << maxdist;
	return 0;
}