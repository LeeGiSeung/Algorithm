#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct PATH {
	int next;
	int cost;
};

int n, m;
bool check[1000];
int uf[1000];
int output = 0;

vector<pair<int, pair<int, int>>> v;

int find(int x) {
	//자기 자신이 부모이면 
	if (x == uf[x]) return x;
	else return uf[x] = find(uf[x]);
}

void _union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x > y) {
		uf[x] = y;
	}
	else {
		uf[y] = x;
	}
}

bool sameparent(int x, int y) {
	x = find(x);
	y = find(y);
	
	if (x == y) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		uf[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++) {
		if (!sameparent(v[i].second.first, v[i].second.second)){
			_union(v[i].second.first, v[i].second.second);
			output += v[i].first;
		}
	}

	cout << output;

	return 0;
}