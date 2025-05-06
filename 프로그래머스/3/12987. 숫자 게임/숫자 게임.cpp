#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, less<int>> a_pq;
priority_queue<int, vector<int>, less<int>> b_pq;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    for (int i = 0; i < A.size(); i++) {
        a_pq.push(A[i]);
        b_pq.push(B[i]);
    }

    while (!a_pq.empty()) {
        if (a_pq.top() >= b_pq.top()) { //b가 이기는 경우의 수만 계산해야함
            a_pq.pop();
        }
        else if (a_pq.top() < b_pq.top()) {
            a_pq.pop();
            b_pq.pop();
            answer++;
        }
    }

    return answer;
}

int main() {

    vector<int> a({ 1,1,1,1 });
    vector<int> b({ 1,1,1,1 });
    solution(a,b);
}

