#include <iostream>
#include <algorithm>

using namespace std;
int n;
int solution[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> solution[i];
    }

    int result = 2000000001;

    int startP = 1;
    int endP = n;
    int startRe, endRe;

    while (startP < endP) {
        int now = solution[startP] + solution[endP];
        int num = abs(now);
        if (result >= num) {
            result = num;
            startRe = solution[startP];
            endRe = solution[endP];
        }
        if (now > 0) endP--;
        else startP++;
    }

    cout << startRe << " " << endRe << "\n";


    return 0;
}
