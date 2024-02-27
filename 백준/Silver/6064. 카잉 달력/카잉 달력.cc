#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>

using namespace std;

int T;
int rx, ry;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//M과 N보다 작거나 같은 두 개의 자연수 x, y
	//x < M 이면 x' = x + 1이고, 그렇지 않으면 x' = 1이다.
	//y < N이면 y' = y + 1이고, 그렇지 않으면 y' = 1이다
	//<M:N>은 그들 달력의 마지막 해로서, 이 해에 세상의 종말이 도래한다는 예언이 전해 온다.

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        int rx, ry; // 타겟 x,y를 구해줌 어느 한 쪽이 1이 되도록
        if (x > y) { // y가 1인 경우
            rx = x - y + 1;
            ry = 1;
        }
        else { // x가 1인 경우
            ry = y - x + 1;
            rx = 1;
        }

        int cnt = 1; // 몇 번째 해
        int nx = 1; // 다음 번째 x
        int ny = 1; // 다음 번째 y
        bool stop = false; // 멸망해 이거나 정답을 찾았거나
        while (!stop) {
            //다음해가 타겟 x와 같은 경우 -> 정답
            if (nx == rx && ny == ry) {
                cnt = cnt + x - rx; // 정답해로 갈 수 있도록 더해줌
                nx = x;
                ny = y;
                stop = true;
            }
            else if (m - nx < n - ny) {// x가 먼저 1이되는 경우
                ny = ny + m - nx + 1;
                cnt = cnt + m - nx + 1;
                nx = 1;
            }
            else if (m - nx > n - ny) { // y가 먼저 1이 되는 경우
                nx = nx + n - ny + 1;
                cnt = cnt + n - ny + 1;
                ny = 1;
            }
            else { // 멸망해인 경우
                cnt = cnt + n - ny;
                nx = m;
                ny = n;
                stop = true;
            }
        }
        if (nx == x && ny == y) { // 정답 해
            cout << cnt << endl;
        }
        else { // 멸망해까지 없는 경우
            cout << -1 << endl;
        }
    }

	return 0;

}