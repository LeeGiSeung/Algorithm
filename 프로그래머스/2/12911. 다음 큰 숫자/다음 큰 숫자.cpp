#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

int solution(int n) {
    int answer = 0;

    //n의 다음 큰 숫자와 n은 2진수로 변환했을 때 1의 갯수가 같습니다.
    //n의 다음수는 큰 숫자들 중에서 가장 작은 수 이여야한다.

    //자연수 n이 주어졌을 때, n의 다음 큰 숫자는 다음과 같이 정의 합니다.
    //일단 n을 진수로 바꿔야함

    string s;
    int tmp = n;

    while (n) {
        s += to_string(n % 2);
        n /= 2;
    }

    int one_count = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            one_count++;
        }
    }

    reverse(s.begin(), s.end());
    tmp++;
    while (true) {
        int c_tmp = tmp;
        int count = 0;
        string test = "";

        while (c_tmp) {
            test += to_string(c_tmp % 2);
            c_tmp /= 2;
        }

        for (int i = 0; i < test.size(); i++) {
            if (test[i] == '1') {
                count++;
            }
        }

        if (count == one_count) {
            break;
        }
        tmp++;
    }

    answer = tmp;

    return answer;
}