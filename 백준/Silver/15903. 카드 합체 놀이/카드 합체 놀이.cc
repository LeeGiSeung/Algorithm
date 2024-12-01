#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int N, A;
long long RESULT = 0;
int a;
priority_queue<long long, vector<long long>, greater<long long>> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> A;

    for (int i = 0; i < N; i++) {
        cin >> a;
        q.push(a);
    }

    for (int i = 0; i < A; i++) {
        long long FIRST, SECOND;
        FIRST = q.top();
        q.pop();
        SECOND = q.top();
        q.pop();
        for (int j = 0; j < 2; j++) {
            q.push(FIRST + SECOND);
        }
    }



    while (!q.empty()) {
        RESULT += q.top();
        q.pop();
    }

    cout << RESULT;

    return 0;

}
