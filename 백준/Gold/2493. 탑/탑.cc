#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

#define endl "\n"

using namespace std;
int n,a;

stack<pair<int,int>> s;

void input() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a;
        while (!s.empty()) {
            if (a <= s.top().second) {
                cout << s.top().first<<" ";
                break;
            }
            else {
                s.pop();
            }
        }
        if (s.empty()) {
            cout << "0 ";
        }
        s.push({ i,a });
    }

}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    input();
    return 0;
}