#include <iostream>
using namespace std;

// 축으로만 이동
// 대각선만으로 이동
// 대각선으로 이동 & 축으로 이동

// 축으로만 이동
long long notCross(long long x, long long y, long long w) {
    return (x + y) * w;
}

// 대각선으로만 이동
long long cross(long long x, long long y, long long w, long long s) {
    long long res = 0;
    int mod = (x + y) % 2;
    res = (max(x, y) - mod) * s;
    res = res + mod * w;
    return res;
}

// 대각선으로 이동 & 축으로 이동
long long mixed(long long x, long long y, long long w, long long s) {
    long long res = 0;
    res = min(x, y) * s;
    res = res + (max(x, y) - min(x, y)) * w;
    return res;
}

int main() {
    long long x, y, w, s;
    cin >> x >> y >> w >> s;

    cout << min(cross(x, y, w, s), min(notCross(x, y, w), mixed(x, y, w, s)));
}