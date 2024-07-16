#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define endl "\n"

using namespace std;

int n;
int list[100001];
int dp[100002];
int result;

void input() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

}

void dynamic() {
    dp[0] = list[0];
    result = list[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + list[i], list[i]);
        result = max(dp[i], result);
     }
    cout << result << endl;
}

int main() {

    input();
    dynamic();

    return 0;
}