#include <iostream>
#include <cstring>

#define endl "\n"

using namespace std;

int n;
string input;
bool a[50];
int result = 0;

void find() {
    int flag = 0;
    memset(a, false, sizeof(a)); // 초기화할 배열의 크기를 올바르게 지정
    char start = input[0];
    a[start - 'a'] = true; // 첫 번째 문자를 방문한 것으로 설정
    for (int i = 1; i < input.size(); i++) {
        if (input[i] != start) { // 현재 문자가 이전 문자와 다른 경우
            if (a[input[i] - 'a']) { // 이미 방문한 문자라면
                flag = 1; // 플래그 설정
                break;
            }
            else {
                a[input[i] - 'a'] = true; // 방문하지 않은 문자라면 방문 표시
            }
            start = input[i]; // 현재 문자를 새로운 시작 문자로 설정
        }
    }
    if (flag == 0) {
        result++;
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> input;
        find();
    }

    cout << result << endl;

    return 0;
}
