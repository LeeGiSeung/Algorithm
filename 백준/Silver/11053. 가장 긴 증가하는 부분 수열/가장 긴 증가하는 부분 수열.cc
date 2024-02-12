#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 10001

using namespace std;

int n, k;
vector<int> a;
vector<int> dp;
int answer = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int T;
    int N, M, K, H;
    int X, Y;
    int answer = 0;

    int dp[1001];
    vector<int> v;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> K;
        v.emplace_back(K);
        int dp_max = 0;

        for (int j = 0; j < v.size(); j++) {
            if (v[i] > v[j]) {
                if (dp_max < dp[j])
                    dp_max = dp[j];
            }
        }
        dp[i] = dp_max + 1;
        answer = max(answer, dp[i]);
    }

    cout << answer << endl;

    return 0;
}