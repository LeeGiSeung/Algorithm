#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

#define MAX 987654321

using namespace std;


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, d, from, to, dis;
    cin >> n >> d;
    vector<int> map(d + 1, MAX);
    vector<pair<int, int>> sc[10001];
    for (int i = 0; i < n; i++) {
        cin >> from >> to >> dis;
        sc[to].push_back({ from,dis });
    }
    map[0] = 0;
    for (int i = 1; i <= d; i++) {
        if (sc[i].size() == 0) map[i] = map[i - 1] + 1;
        else {
            for (auto v : sc[i]) { 
                map[i] = min(map[i], min(map[i - 1] + 1, map[v.first] + v.second));
            }
        }
    }
    cout << map[d] << "\n";
    return 0;
}