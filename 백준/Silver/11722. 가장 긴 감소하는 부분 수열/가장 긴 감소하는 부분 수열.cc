#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define endl "\n"

using namespace std;

int ary[1001] = { 0 };
int n, a;
int dp[1001] = {1};
int tmp = 0;

int main() {

    cin >> n;
    //수열 A가 주어졌을 때, 가장 긴 감소하는 부분 수열을 구하는 프로그램을 작성하시오.

    //    예를 들어, 수열 A = { 10, 30, 10, 20, 20, 10 } 인 경우에 가장 긴 감소하는 부분 수열은 A = { 10, 30, 10, 20, 20, 10 }  이고, 길이는 3이다.

    //    입력
    //    첫째 줄에 수열 A의 크기 N(1 ≤ N ≤ 1, 000)이 주어진다.

    //    둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1, 000)

    for (int i = 1; i <= n; i++) {
        cin >> ary[i];
    }

    //dp
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        //ary
        for (int j = 1; j <= i; j++) {
            if (ary[i] < ary[j]) {
                dp[i] = max(dp[j] + 1,dp[i]);
            }
        }
        tmp = max(tmp, dp[i]);
    }
    
    cout << tmp;

    return 0;
}
