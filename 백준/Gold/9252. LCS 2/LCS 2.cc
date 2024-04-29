#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
string a, b;
int dp[1001][1001];
string result;
void input() {
    cin >> a;
    cin >> b;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            dp[i][j] = 0;
        }
    }
}

void solve() {
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i = a.size();
    int j = b.size();

    while (i >= 1 && j >= 1) {
        if (dp[i][j] > dp[i - 1][j] && dp[i][j] > dp[i][j - 1] && dp[i - 1][j - 1] == dp[i - 1][j]) {
            result += b[j - 1];
            i--;
            j--;
        }
        else if (dp[i][j] == dp[i - 1][j] && dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else if (dp[i][j] == dp[i][j - 1] && dp[i][j - 1] > dp[i - 1][j]) {
            j--;
        }
        else j--;
    }

    reverse(result.begin(), result.end());

    if (result.size() < 1) {
        cout << 0;
    }
    else {
        cout << result.size() << "\n";
        cout << result;
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    input();
    solve();

    return 0;


}