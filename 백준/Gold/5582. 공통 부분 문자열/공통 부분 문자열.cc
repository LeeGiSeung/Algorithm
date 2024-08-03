#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
 
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int ans = 0;
    // dp[s2][s1];
    vector<vector<int>> dp(s2.length(), vector<int>(s1.length(), 0));
    for (int i = 0; i < s2.length(); i++) {
        for (int j = 0; j < s1.length(); j++) {
            if (s2[i] == s1[j]) {
                dp[i][j] = 1;
                if (i >= 1 && j >= 1) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans;
    return 0;
}
