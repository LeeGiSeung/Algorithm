#include <iostream>
#include <cstring>
using namespace std;

char tictac[4][4];

bool check_win(char player) {
    // 가로, 세로, 대각선 승리 조건 확인
    for (int i = 1; i <= 3; i++) {
        if (tictac[i][1] == player && tictac[i][2] == player && tictac[i][3] == player) return true;
        if (tictac[1][i] == player && tictac[2][i] == player && tictac[3][i] == player) return true;
    }
    if (tictac[1][1] == player && tictac[2][2] == player && tictac[3][3] == player) return true;
    if (tictac[1][3] == player && tictac[2][2] == player && tictac[3][1] == player) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        string s;
        cin >> s;
        if (s == "end") break;

        memset(tictac, ' ', sizeof(tictac));
        int f_count = 0;  // X의 개수
        int s_count = 0;  // O의 개수

        // 입력된 문자열로 틱택토 판을 채움
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                tictac[i][j] = s[(i - 1) * 3 + (j - 1)];
                if (tictac[i][j] == 'X') f_count++;
                if (tictac[i][j] == 'O') s_count++;
            }
        }

        // X가 승리한 경우, O가 승리한 경우
        bool x_wins = check_win('X');
        bool o_wins = check_win('O');

        // 유효성 검사
        bool valid = true;
        if (s_count > f_count || f_count > s_count + 1) {
            // X와 O의 수가 올바르지 않음
            valid = false;
        } else if (x_wins && o_wins) {
            // X와 O가 동시에 승리할 수 없음
            valid = false;
        } else if (x_wins && f_count != s_count + 1) {
            // X가 승리했는데 X의 개수가 O의 개수보다 1개 많지 않음
            valid = false;
        } else if (o_wins && f_count != s_count) {
            // O가 승리했는데 X의 개수와 O의 개수가 같지 않음
            valid = false;
        } else if (!x_wins && !o_wins && f_count + s_count != 9) {
            // 승리자가 없는데 빈 칸이 남아 있는 경우
            valid = false;
        }

        // 결과 출력
        if (valid) {
            cout << "valid" << "\n";
        } else {
            cout << "invalid" << "\n";
        }
    }

    return 0;
}
