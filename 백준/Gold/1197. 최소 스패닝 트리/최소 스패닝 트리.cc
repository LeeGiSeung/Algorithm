#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int v, e;
int mst[10001];
vector < pair<int, pair<int, int>>> li;
int result = 0;

//-2,147,483,648보다 크거나 같고, 2,147,483,647보다 작거나 같은 데이터만 입력으로 주어진다.

int find(int x) {
	if (mst[x] == x) return x;
	return mst[x] = find(mst[x]);
}	

void _union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x > y) {
		mst[x] = y;
	}
	else {
		mst[y] = x;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> v >> e;

	//초기화
	for (int i = 0; i <= v; i++) {
		mst[i] = i;
	}

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		li.push_back({ c,{a,b} });
	}

	sort(li.begin(), li.end());

	for (int i = 0; i < li.size(); i++) {
		int x = li[i].second.first;
		int y = li[i].second.second;
		//부모가 같이 않으면 사이클이 발생할 수 없음
		if (find(x) != find(y)) {
			//연결함
			_union(x, y);
			result += li[i].first;
		}
	}

	cout << result;

	return 0;
}