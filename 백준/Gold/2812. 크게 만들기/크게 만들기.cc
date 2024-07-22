#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    string a;

    // 입력 받기
    cin >> n >> k >> a;

    stack<char> s;

    for (int i = 0; i < a.size(); i++) {
        char ba = a[i];
        // 스택이 비어있지 않고, 스택의 상단이 현재 문자보다 작고, 지울 수 있는 문자가 남아있을 때
        while (!s.empty() && s.top() < ba && k > 0) {
            s.pop();
            k--;
        }
        s.push(ba);
    }

    // 여전히 k가 남아있다면, 스택의 뒤에서부터 k개를 pop
    while (k > 0) {
        s.pop();
        k--;
    }

    vector<char> result;
    // 스택에서 문자를 빼내어 벡터에 저장 (역순)
    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }

    // 결과 벡터를 뒤집어서 올바른 순서로 변경
    reverse(result.begin(), result.end());

    // 결과 출력
    for (char c : result) {
        cout << c;
    }

    return 0;
}
