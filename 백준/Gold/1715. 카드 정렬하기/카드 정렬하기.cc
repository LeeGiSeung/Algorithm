#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <deque>

using namespace std;
int n,a;

//top이 가장 작길 원함 (오름 차순)
priority_queue<int,vector<int>,greater<int>> q;
int result;
int tmp;

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        q.push(a);
    }

    if (n == 1) {
        cout << 0;
        return 0;
    }

    while (!q.empty()) {
        tmp = 0;
        tmp += q.top();
        q.pop();
        if (!q.empty()) {
            tmp += q.top();
            q.pop();
            if (!q.empty()) {
                q.push(tmp);
            }
        }
        result += tmp;
        
    }

    cout << result;

    return 0;
}
