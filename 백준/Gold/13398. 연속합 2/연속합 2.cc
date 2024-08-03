#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int arr[100001];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // dp1[i]는 i를 포함한 최대 연속 합
    int dp1[100001];
    // dp2[i]는 i를 제거한 최대 연속 합
    int dp2[100001];
    
    dp1[0] = arr[0];
    dp2[0] = 0;
    
    int result = arr[0];
    
    for (int i = 1; i < n; i++) {
        dp1[i] = max(dp1[i-1] + arr[i], arr[i]);
        dp2[i] = max(dp2[i-1] + arr[i], dp1[i-1]);
        result = max({result, dp1[i], dp2[i]});
    }
    
    cout << result << endl;
    
    return 0;
}
