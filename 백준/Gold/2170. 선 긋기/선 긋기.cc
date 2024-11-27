#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N;

vector<pair<int, int>> v;
int before = 0;
long long RESULT;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({ a,b });
    }

    sort(v.begin(), v.end());
    int start = v[0].first;
    int end = v[0].second;

    //before는 끝점임
    for (int i = 1; i < v.size(); i++) {
        //선이 이어져 있을때
        int s = v[i].first;
        int e = v[i].second;
        if (end >= s) {
            if (end < e) {
                end = e;
            }
        }
        //선이 이어져 있지 않을 때
        else {
            RESULT += (end - start);
            end = e;
            start = s;
        }
    }
    RESULT += end - start;
    cout << RESULT;

    return 0;

}
