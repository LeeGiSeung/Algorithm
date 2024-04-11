#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include <limits>

using namespace std;

vector<pair<int, int>> city[1001];
int route[1001];
int value[1001];
int n, m, x, y;
int result = numeric_limits<int>::max();
int result_ct;

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        city[a].emplace_back(b, c);
    }
    cin >> x >> y;
}

void solve() {
    deque<pair<int, pair<int, int>>> q;
    q.push_back({ 1, {x, 0} });
    fill(value, value + n + 1, numeric_limits<int>::max());
    value[x] = 0;

    while (!q.empty()) {
        int ct = q.front().first;
        int start = q.front().second.first;
        int distance = q.front().second.second;
        q.pop_front();

        if (distance > result || value[start] < distance)
            continue;

        if (start == y) {
            result = distance;
            result_ct = ct;
        }

        for (const auto& p : city[start]) {
            int next_point = p.first;
            int next_distance = p.second;
            if (value[next_point] > distance + next_distance) {
                route[next_point] = start;
                value[next_point] = next_distance + distance;
                q.push_back({ ct + 1, {next_point, next_distance + distance} });
            }
        }
    }
    cout << result << "\n";
    cout << result_ct << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();

    deque<int> routev;
    int temp = y;
    routev.push_back(y);

    while (temp != x) {
        routev.push_back(route[temp]);
        temp = route[temp];
    }

    for (int i = routev.size() - 1; i >= 0; i--) {
        cout << routev[i] << " ";
    }

    return 0;
}
