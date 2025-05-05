#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    multiset<int, less<int>> ms;

    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i].find("I") == 0) {
            string number = operations[i].substr(operations[i].find("I") + 2, operations[i].size() - 1);

            int int_number = stoi(number);

            ms.insert(int_number);

        }
        else if (operations[i].find("D 1") == 0) {
            if (ms.empty()) continue;
            ms.erase(--ms.end());
        }
        else if (operations[i].find("D -1") == 0) {
            if (ms.empty()) continue;
            ms.erase(ms.begin());
        }
    }

    if (ms.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(*(--ms.end()));
        answer.push_back(*ms.begin());
    }

    return answer;

}

int main() {
    //4, [[1, 0, 0, 1], [0, 1, 1, 0], [0, 1, 1, 1], [1, 0, 1, 1]]
    vector<string> v({ "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" });

    solution(v);

}

