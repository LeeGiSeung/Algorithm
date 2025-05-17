#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;

    long long cur = 0;
    long long zero = 0;

    vector<int> v;

    for (int i = 0; i < sequence.size(); i++) {
        v.push_back(sequence[i]);
        if (i % 2 == 0) {
            v[i] *= -1;
        }
    }

    for (int i = 0; i < sequence.size(); i++) {
        cur = max(cur, zero) + v[i];
        answer = max(cur, answer);
    }
    
    cur = 0;

    for (int i = 0; i < sequence.size(); i++) {
        cur = max(cur, zero) - v[i];
        answer = max(cur, answer);
    }

    return answer;
}

int main() {

    vector<int> v({ 2, 3, -6, 1, 3, -1, 2, 4 });
    //vector<vector<string>> v({ {"ICN", "ABC"}, {"ICN", "BBB"}, {"JFK", "HND"} });

    solution(v);

    return 0;
}