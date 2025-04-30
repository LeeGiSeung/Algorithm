#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(string s) {
    bool answer = true;

    string test = s;

    int left = 0;
    int right = 0;

    for (int i = 0; i < test.size(); i++) {
        if (test[i] == '(') {
            left++;
        }
        else if (test[i] == ')') {
            left--;
            if (left < 0) {
                return false;
            }
        }
    }

    if (left > 0) {
        return false;
    }

    return answer;
}
