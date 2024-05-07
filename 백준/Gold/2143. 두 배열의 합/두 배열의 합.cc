#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int t, n, m;
long long cnt = 0;
vector<int> v, w;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    cin >> t;
    cin >> n;

    vector<int> v1(n);
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    cin >> m;
    vector<int> v2(m);
    for (int i = 0; i < m; i++) {
        cin >> v2[i];
    }

    for (int i = 0; i < n; i++) {
        int sum = v1[i];
        v.push_back(sum);
        for (int j = i + 1; j < n; j++) {
            sum += v1[j];
            v.push_back(sum);
        }
    }

    for (int i = 0; i < m; i++) {
        int sum = v2[i];
        w.push_back(sum);
        for (int j = i + 1; j < m; j++) {
            sum += v2[j];
            w.push_back(sum);
        }
    }

    sort(v2.begin(), v2.end());

    for (int i = 0; i < v.size(); i++) {
        int c = t - v[i];
        int lower = lower_bound(w.begin(), w.end(), c) - w.begin();
        int upper = upper_bound(w.begin(), w.end(), c) - w.begin();

        cnt += (upper - lower);
    }

    cout << cnt;
    return 0;

}
