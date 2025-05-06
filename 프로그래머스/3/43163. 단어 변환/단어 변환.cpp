#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check[51];

bool check_trans(string &cur_str, vector<string> words) {

    bool match = false;

    string next_cur;

    for (int i = 0; i < words.size(); i++) {
        if (check[i]) continue;

        int count = 0;

        for (int j = 0; j < cur_str.size(); j++) { //모든 단어의 길이는 똑같음 한 번에 한 개의 알파벳만 바꿀 수
            if (cur_str[j] != words[i][j]) count++;

            if (count > 1) {
                break;
            }
        }

        if (count == 1) {
            match = true;
            check[i] = true;
            next_cur = words[i];
        }
    }

    if (!match) return false;

    cur_str = next_cur;

    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    string cur_str = begin;

    while (true) {
        if (check_trans(cur_str, words)) {
            answer++;
        }
        else {
            answer = 0;
            break;
        }
        
        if (cur_str == target) break;
    }
    return answer;
}
int main() {

    vector<string> v({ "hot", "dot", "dog", "lot", "log", "cog" });
    solution("hit", "cog", v);
}

