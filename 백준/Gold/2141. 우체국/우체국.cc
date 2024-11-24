#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> v;
int n;
long long RESULT = 0;
long long CUR_RESULT = 0;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({ a,b });
        RESULT += b;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        CUR_RESULT += v[i].second;
        if (CUR_RESULT >= ((RESULT + 1) / 2)) {
            cout << v[i].first;
            break;
        }
    }

    return 0;

}
