#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    map<string, int> m;

    for (int i = 0; i < number.size(); i++) {
        m[want[i]] = number[i];
    }

    for (int i = 0; i < discount.size() - 9; i++) { //10일간 할인을 보면 됨
        map<string, int> q_m;
        for (int j = 0; j < 10; j++) {
            q_m[discount[i + j]] += 1;
        }

        bool match = true;

        for (auto cur : m) {
            if (q_m[cur.first] != cur.second) { //현재 할인 품목 != 내가 원하는 할인
                match = false;
                break;
            }
        }
        if (match == true) {
            answer++;
        }
    }

    return answer;
}

int main() {
    vector<string> want = { "banana", "apple", "rice", "pork", "pot" }; vector<int> number = { 3, 2, 2, 2, 1 }; vector<string> discount = { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" };
    solution(want, number, discount);
}