#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define endl "\n"

using namespace std;

int n;
int sdoku[9][9];
bool row_check[9][10] = { false };
bool col_check[9][10] = { false };
bool square_check[9][10] = { false };

bool solve(int i, int j) {
    if (i == 9) return true;
    if (j == 9) return solve(i + 1, 0);
    if (sdoku[i][j] != 0) return solve(i, j + 1);

    int square_index = (i / 3) * 3 + (j / 3);
    for (int num = 1; num <= 9; num++) {
        if (!row_check[i][num] && !col_check[j][num] && !square_check[square_index][num]) {
            sdoku[i][j] = num;
            row_check[i][num] = true;
            col_check[j][num] = true;
            square_check[square_index][num] = true;
            
            if (solve(i, j + 1)) return true;

            sdoku[i][j] = 0;
            row_check[i][num] = false;
            col_check[j][num] = false;
            square_check[square_index][num] = false;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sdoku[i][j];
            if (sdoku[i][j] != 0) {
                int num = sdoku[i][j];
                row_check[i][num] = true;
                col_check[j][num] = true;
                int square_index = (i / 3) * 3 + (j / 3);
                square_check[square_index][num] = true;
            }
        }
    }

    solve(0, 0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sdoku[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
