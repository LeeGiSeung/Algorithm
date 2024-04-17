#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        cin >> arr[i];
    }

    int ans = 2000000001;

    int start = 1, end = n;
    int first, second;
    while(start<end) {
        int now = arr[start] + arr[end];
        int num = abs(now);
        if(ans>num) {
            ans = num;
            first = arr[start], second = arr[end];
        }
        if(now>0) end--;
        else start++;
    }
    cout << first << " " << second;
    return 0;
}