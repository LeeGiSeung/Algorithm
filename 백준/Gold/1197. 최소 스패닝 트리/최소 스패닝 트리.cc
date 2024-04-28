#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int v, e;
vector<pair<int, pair<int, int>>> g;
int parent[10001];

int find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

bool same_parent(int s, int e) {
    s = find(s);
    e = find(e);
    if (s == e)return true;
    else return false;
}

void uni(int x, int y) {
    x = find(x);
    y = find(y);
    parent[y] = x;
}

void input() {
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g.push_back({ c,{a,b} });
    }
    sort(g.begin(), g.end());
    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }
}

void solve() {
    int cnt = 0;
    for (int i = 0; i < g.size(); i++) {
        int cost = g[i].first;
        int start = g[i].second.first;
        int end = g[i].second.second;
        if (!same_parent(start, end)) {
            uni(start, end);
            cnt += cost;
        }
    }
    cout << cnt;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    input();
    solve();

    return 0;


}
