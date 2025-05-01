#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

bool check[2501];

vector<int> solution(int n, vector<string> words) {
    vector<int> answer; //그 사람이 자신의 몇 번째 차례에 탈락하는지

    map<string, bool> m;
    m[words[0]] = true;

    //사람은 1~n번 까지

    int people = 2;
    int loop = 1;

    char past = ' ';
    past = words[0].back();

    for (int i = 1; i < words.size(); i++) {
        if (m[words[i]] == true) { //이미 사용한 단어일때
            answer.push_back(people);
            answer.push_back(loop);
            return answer;
        }

        if (past != words[i].front()) { //끝말 잇기가 안될때
            answer.push_back(people);
            answer.push_back(loop);
            return answer;
        }

        m[words[i]] = true;
        past = words[i].back();

        people += 1;
        if (people > n) {
            people = 1;
            loop++;
        }

    }
    answer.push_back(0);
    answer.push_back(0);
    //만약 주어진 단어들로 탈락자가 생기지 않는다면, [0, 0]
    return answer;
}

int main() {
    vector<string> v{ "hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive" };
    solution(3, v);
}