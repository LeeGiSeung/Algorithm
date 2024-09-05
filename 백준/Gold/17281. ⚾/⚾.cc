#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

int s[50][9];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 9; j++)
            cin >> s[i][j]; // 각 선수가 이닝에서 얻는 결과를 입력 받음.

    int np[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

    int ans = 0;
    while(next_permutation(np,np+8)){

        deque<int> h;
        for (int i = 0; i < 3; i++) h.push_back(np[i]);   // 타자 순서
        h.push_back(0); // 4번 타자에 1번 선수를 넣음
        for (int i = 3; i < 8; i++) h.push_back(np[i]);

        int ining = 0, score = 0;
        while (ining < n) {   // 게임 시작
            int out = 0;    // 현재 이닝에서의 out 횟수
            queue<int> base; for (int i = 0; i < 3; i++) base.push(0);   // base를 모두 0으로 채움

            while (out < 3) { // 3아웃이 발생할 때까지 이닝 진행
                int cur = h.front(); // 현재 타자
                h.pop_front(); h.push_back(cur);   // 현재 타자를 마지막 타자로 다시 넣음
                if (s[ining][cur] == 0) out++;   // 아웃인 경우
                else {   // 아웃이 아닌 경우
                    if (base.front() == 1) score++;  // 3루수 홈으로 진루
                    base.push(1); base.pop();   // 1루로 진루
                    for (int i = 0; i < s[ining][cur] - 1; i++) { // 나머지 진루
                        if (base.front() == 1) score++;
                        base.pop(); base.push(0);
                    }
                }
            }
            ining++;    // 이닝 증가
        }   // 게임 종료
        ans = max(ans, score);
    } 
    cout << ans;
}