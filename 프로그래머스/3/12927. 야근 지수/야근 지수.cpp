#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    long long sum = 0;

    

    for (int i = 0; i < works.size(); i++) {
        sum += works[i];
    }

    sum -= (works.size() / n) * n;

    sum -= (works.size() % n);

    int a = sum / n;
    int b = sum % n;

    for (int i = 0; i < works.size(); i++) {
        if (b > 0) {
            answer += (a + 1) * (a + 1);
            b--;
        }
    }

    return answer;
}

int main() {


}

