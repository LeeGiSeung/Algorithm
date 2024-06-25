#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n;
int number[13];
int op[4];
int min_result = 1000000001;
int max_result = -1000000001;


void backtracking(int pos, int x) {
    if (x == n) {
        if (pos < min_result) min_result = pos;
        if (pos > max_result) max_result = pos;
    }
    else if (x < n) {

        for (int i = 0; i < 4; i++) {
            if (op[i] > 0 && i == 0) {
                    op[i] -= 1;
                    backtracking(pos + number[x], x + 1);
                    op[i] += 1;
            }
            if (op[i] > 0 && i == 1) {
                    op[i] -= 1;
                    backtracking(pos - number[x], x + 1);
                    op[i] += 1;
            }
            if (op[i] > 0 && i == 2) {
                    op[i] -= 1;
                    backtracking(pos * number[x], x + 1);
                    op[i] += 1;
            }
            if (op[i] > 0 && i == 3) {
                    op[i] -= 1;
                    backtracking(pos / number[x], x + 1);
                    op[i] += 1;
            }
        }
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> number[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    backtracking(number[0], 1);

    cout << max_result << "\n";
    cout << min_result;

    return 0;

}