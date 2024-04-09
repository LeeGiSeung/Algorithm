#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
int n, m, a, b, c;
vector<pair<int, int>> city[101];
int result[101];
int l = 1000000000;

void input()
{
    cin >> n;
    cin >> m;

    while (m--) {
        cin >> a >> b >> c;
        city[a].push_back(make_pair(b, c));
    }

}

void solve() {
    for (int i = 1; i <= n; i++) {

        for (int k = 0; k <= n; k++) {
            result[k] = l;
        }

        deque<pair<int, int>> q;
        q.push_back(make_pair(i, 0));

        while (!q.empty()) {

            int start = q.front().first;
            int cost = q.front().second;
            q.pop_front();

            for (int j = 0; j < city[start].size(); j++) {
                int next_place = city[start][j].first;
                int next_cost = city[start][j].second;

                if (cost + next_cost < result[next_place]) {
                    q.push_back(make_pair(next_place, cost + next_cost));
                    result[next_place] = cost + next_cost;
                }
                else {
                    continue;
                }

            }
        }

        for (int p = 1; p <= n; p++) {
            if (p == i || result[p] == l) {
                cout << "0 ";
            }
            else {
                cout << result[p] << " ";
            }
        }
        cout << "\n";

    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();

    return 0;

}