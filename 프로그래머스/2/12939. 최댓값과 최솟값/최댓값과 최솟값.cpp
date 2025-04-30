#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> stringvector;

string solution(string s) {

        string answer;
    string fast;
    vector<int> v;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            v.push_back(stoi(fast));
            fast = "";
        }
        else {
            fast += s[i];
        }
    }

    v.push_back(stoi(fast)); //마지막 숫자도 추가

    sort(v.begin(), v.end());

    answer += to_string(v[0]) + " " + to_string(v[v.size() - 1]);

    return answer;
}