#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N;
int COUNT = 0;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int HIGH_LEVEL = v[v.size() - 1];
    for (int i = v.size() - 2; i >= 0; i--) {
        while (v[i] >= HIGH_LEVEL) {
            v[i]--;
            COUNT++;
        }
        HIGH_LEVEL = v[i];
    }

    cout << COUNT;

    return 0;

}
