#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int n, k;
int coin[10100];
int dp[10100];
int ct = 0;

void input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
}

void dynamic() {
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= k; j++) {
            dp[j] += dp[j - coin[i]];
        }
    }
}

int main() {
    input();
    dynamic();
    cout << dp[k] << endl;
    return 0;
}
