#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer({0,0});

    set<string> s;

    for (int i = 0; i < gems.size(); i++) {
        s.insert(gems[i]);
    }

    int count = s.size(); //종류 갯수
    int start_index = 0;
    int end_index = 0;
    int curcount = 0;
    map<string, int> m;

    while (true) {
        if (curcount == count) { //Maxcount에 도달했을시
            const string &a = gems[start_index++];
            if (--m[a] == 0) {
                curcount--;
            }
        }
        else {
            if (end_index == gems.size()) {
                break;
            }
            //MaxCount에 도달못했으면 endindex를 늘려야함
            const string& a = gems[end_index++];
            if (m[a]++ == 0) { //만약 아직 갯수가 없었으면 그냥 count 늘림
                curcount++;
            }
        }
        if (curcount == count) {
            if ((answer[0] == 0 && answer[1] == 0) || end_index - start_index - 1< answer[1] - answer[0]) {
                answer = { start_index + 1, end_index};
            }
        }
    }

    return answer;
}

int main() {
    vector<string> v1({
       "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"
        });

    solution(v1);

    return 0;
}