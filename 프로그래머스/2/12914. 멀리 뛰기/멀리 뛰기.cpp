#include <string>
#include <vector>
#include <queue>

using namespace std;

int st[2001];

long long solution(int n) {
    long long answer = 0;

    //4	5
    //3	3

    st[0] = 0;
    st[1] = 1;
    st[2] = 2;

    for(int i =3; i<=n; i++){
        st[i] = st[i - 1] + st[i - 2];
        st[i] %= 1234567;
    }
    answer = st[n];
    return answer;
}

int main() {
    solution(4);
}