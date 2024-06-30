#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

#define endl "\n"

using namespace std;
int n;
int result = 1;
int dp[100001][3];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    cin >> n;

    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = 1;

    for (int i = 1; i < n; i++) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % 9901;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i-1][2]) % 9901;
    }

    cout << (dp[n-1][0] + dp[n-1][1] + dp[n-1][2]) %9901 << endl;

    return 0;

}