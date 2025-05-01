#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int n)
{
    int ans = 0;

    //n이 목적지
    //도달할 수 없을 경우라는 말이 없으니 무조건 도달 할 수 있다는 거임
    //순간이동 할 수 있을때 순간이동 하는게 가장 효울적임
    while (true) {
        if (n == 0) break;

        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n--;
            ans++;
        }
    }

    return ans;
}

int main() {
    cout<<solution(5000);
    return 0;
}