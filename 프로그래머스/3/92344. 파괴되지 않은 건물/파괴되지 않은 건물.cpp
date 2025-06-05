#include <string>
#include <vector>
#include <iostream>
using namespace std;

int check[1010][1010]; // 충분히 큰 고정 배열

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();

    // skill 처리
    for (int i = 0; i < skill.size(); i++) {
        int type = skill[i][0];
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int degree = skill[i][5];
        
        if (type == 1) degree = -degree; // 파괴이면 음수로
        // imos marking
        check[r1][c1] += degree;
        check[r1][c2 + 1] -= degree;
        check[r2 + 1][c1] -= degree;
        check[r2 + 1][c2 + 1] += degree;
    }

    // 가로 누적합
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            check[i][j] += check[i][j - 1];
        }
    }

    // 세로 누적합
    for (int j = 0; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            check[i][j] += check[i - 1][j];
        }
    }

    // 최종 계산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] + check[i][j] > 0) {
                answer++;
            }
        }
    }

    return answer;
}
