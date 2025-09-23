#include <string>
#include <vector>
using namespace std;

long long findTile(long long& num) {
    if (num == 1) return 0;
    long long i = 2, res = 1;
    while (i * i <= num) {// 시간초과를 방지하기위해 제곱근까지만 
        if (num % i == 0) {// 나누어진다면 
            res = i;// 정답 갱신
            if (num / i <= 10000000) return (num / i);// 예시로 num = 26, i = 2일때이면 바로 13을 리턴해준다.
        }
        i++;
    }
    return res;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for (; begin <= end; begin++) {
        answer.push_back(findTile(begin));
    }
    return answer;
}