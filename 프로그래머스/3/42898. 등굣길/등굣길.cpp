#include <string>
#include <vector>

using namespace std;

int dp[101][101];
bool check[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    //오른쪽과 아래쪽으로만 움직여

    for (int i = 0; i < puddles.size(); i++) {
        int x = puddles[i][0];
        int y = puddles[i][1];
        check[y][x] = true;
    }

    dp[1][1] = 1;
    check[1][1] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (check[i][j]) continue; //물가면 못감
            if (i == 1 && dp[i][j-1] != 0) {
                dp[i][j] = 1; //끝쪽이면 1가지 경우의 수 밖에 없음
            }
            else if (j == 1 && dp[i-1][j] != 0) {
                dp[i][j] = 1; //끝쪽이면 1가지 경우의 수 밖에 없음
            }
            else {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
            }
        }
    }

    answer = dp[n][m] % 1000000007;

    return answer;
}


int main() {

    vector<vector<int>> v({ { 2, 2 } });
    solution(4, 3, v);
}

