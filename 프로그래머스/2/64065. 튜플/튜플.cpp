#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    string number = "";

    map<string, int> m;

    for (int i = 1; i < s.size() - 2; i++) { //처음 ,끝 {}는 제외함
        if (s[i] == '{' || s[i] == '}') continue; 
        else if (s[i] == ',') {
            if (m.find(number) != m.end()) {
                auto index = m.find(number);
                index->second += 1;
            }
            else {
                m.insert({ number, 1 });
            }
            number = "";
        }
        else {
            number += s[i];
        }
    }

    //마지막 숫자 넣어주기
    if (m.find(number) != m.end()) {
        auto index = m.find(number);
        index->second += 1;
    }
    else {
        m.insert({ number, 1 });
    }

    vector<pair<string, int>> v(m.begin(), m.end()); //vector로 복사

    sort(v.begin(), v.end(),
        [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

    for (int i = 0; i < v.size(); i++) {
        answer.push_back(stoi(v[i].first));
    }

    return answer;
}

int main() {

    string a = "{{2},{2,1},{2,1,3},{2,1,3,4}}";

    solution(a);
}