#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

#define endl "\n"

using namespace std;
int n, c;
int low, high, mid;
int ans = 0;
vector<int> house;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        house.push_back(a);
    }

    int start = 1;
    sort(house.begin(), house.end());;
    high = house[n-1] - house[0];

 
    while (start <= high) {
        int router = 1;

        low = house[0];
        mid = (high + start) / 2;

        for (int i = 1; i < n; i++) {
            if (house[i] - low >= mid) {
                router++;
                low = house[i];
            }
        }

        if (router >= c) {
            ans = max(ans, mid);
            start = mid + 1;
        }
        else {
            high = mid-1;
        }

    }

    cout << ans;
    return 0;
}