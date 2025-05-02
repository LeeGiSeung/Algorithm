#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (long long i = left; i <= right; i++) {
        int x = i % n + 1;
        int y = i / n + 1;

        long long z = x > y ? x : y; //x 보다 y가 크면 x값이 z 아니면 y값이 z

        answer.push_back(z);

    }

    return answer;
}

int main() {
    solution(3,2,5);
}