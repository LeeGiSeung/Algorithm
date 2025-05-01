#include <string>
#include <vector>

using namespace std;

int ary[100001];

int solution(int n) {
    int answer = 0;

    ary[0] = 0;
    ary[1] = 1;
    ary[2] = 1;

    for (int i = 3; i <= n; i++) {
        ary[i] = ary[i - 1] + ary[i - 2];
        ary[i] %= 1234567;
    }

    answer = ary[n];

    return answer;
}