#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n;
int table[10001];
int dp[10001];

// 바로 다음잔을 고르거나 다다음 잔을 고르거나

void dynamic() {
    dp[0] = 0;
    dp[1] = table[1];
    dp[2] = table[1] + table[2];
    for (int i = 3; i <= n; i++) {
        dp[i] = max({ dp[i - 3] + table[i - 1] + table[i], dp[i - 2] + table[i], dp[i - 1] });
    }
    cout << dp[n] << endl;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> table[i];
    }

    dynamic();
   
    return 0;

}