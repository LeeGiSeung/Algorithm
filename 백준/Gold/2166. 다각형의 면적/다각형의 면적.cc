#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using pdd = pair<double, double>;
int N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    vector<pdd> v;
    for (int i = 0, x, y; i < N; ++i)
    {
        cin >> x >> y;
        v.push_back({x, y});
    }
    v.push_back(v.front());
    double sum = 0;
    for (int i = 0; i < N; ++i)
    {
        sum += v[i].first * v[i + 1].second - v[i + 1].first * v[i].second;
    }

    cout.precision(1);
    cout << fixed;
    cout << abs(sum / 2);
    return 0;
}