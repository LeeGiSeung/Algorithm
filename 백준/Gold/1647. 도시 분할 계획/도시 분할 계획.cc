#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int v, e;
vector<pair<int, pair<int, int>>> g;
int parent[100002];
int cost, start, en;
deque<int>max_cost;

int find(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

bool same_parent(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return true;
    else return false;
}

void uni(int x, int y) {
    x = parent[x];
    y = parent[y];
    if (x == y) return;
    parent[y] = x;
    v--;
}

void input() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g.push_back({ c,{a,b} });
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    sort(g.begin(), g.end());
}

void solve() {
    int cnt = 0;
    for (int i = 0; i < g.size(); i++) {
        cost = g[i].first;
        start = g[i].second.first;
        en = g[i].second.second;
        if (!same_parent(start, en)) {
            uni(start, en);
            cnt += cost;
            max_cost.push_back(cost);
        }
    }
    int k = 0;
    for (int i = 0; i < max_cost.size(); i++) {
        if (k < max_cost[i]) {
            k = max_cost[i];
        }
    }
    cout << cnt-k;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    input();
    solve();

    return 0;


}