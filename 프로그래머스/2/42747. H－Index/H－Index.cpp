#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//어떤 과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end(), greater<>());

    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= i + 1) {
            answer = i + 1;
        }
    }

    return answer;
}

int main() {

    vector<int> b = { 3, 0, 6, 1, 5 };

    solution(b);
}