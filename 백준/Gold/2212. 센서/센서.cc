#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, result = 0;
vector<int> v;
vector<int> d;

void solution() {
    sort(v.begin(), v.end());

    for (int i = 1; i < v.size(); i++) {
        d.push_back(v[i] - v[i - 1]);
    }

    sort(d.rbegin(), d.rend());

    for (int i = K - 1; i < d.size(); i++) {
        result += d[i];
    }

    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    cin >> K;

    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        v.push_back(a);
    }

    solution();

    return 0;
}