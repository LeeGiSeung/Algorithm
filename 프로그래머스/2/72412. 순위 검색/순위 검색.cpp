#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
using namespace std;

unordered_map<string, vector<int>> um;

// info 각 데이터로부터 16가지 케이스 만들어서 map에 저장
void addCases(vector<string>& s, int score) {
    for (int i = 0; i < 16; i++) {
        string str = "";
        int num = i;
        for (int j = 3; j >= 0; j--) {
            if (num % 2 == 0) str = "-" + str;
            else str = s[j] + str;
            num /= 2;
        }
        um[str].push_back(score);
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    vector<vector<string>> infolist;

    // info 문자열 나누는 부분 그대로 사용
    for (int i = 0; i < info.size(); i++) {
        string s = info[i];
        int index = 0;
        vector<string> data;
        while (s.find(" ", index) != string::npos) {
            int tmp = s.find(" ", index);
            string cur = s.substr(index, tmp - index);
            data.push_back(cur);
            index = tmp + 1;
        }
        string cur = s.substr(index, s.size() - index);
        data.push_back(cur);
        infolist.push_back(data);
    }

    // map에 점수 저장
    for (auto& data : infolist) {
        int score = stoi(data[4]);
        addCases(data, score);
    }

    // map 내 벡터 정렬
    for (auto& p : um) {
        sort(p.second.begin(), p.second.end());
    }

    // query 문자열 나누는 부분 그대로 사용
    vector<vector<string>> querylist;
    for (int i = 0; i < query.size(); i++) {
        string s = query[i];
        int index = 0;
        vector<string> data;
        while (s.find(" and ", index) != string::npos) {
            int tmp = s.find(" and ", index);
            string cur = s.substr(index, tmp - index);
            data.push_back(cur);
            index = tmp + 5;
        }
        while (s.find(" ", index) != string::npos) {
            int tmp = s.find(" ", index);
            string cur = s.substr(index, tmp - index);
            data.push_back(cur);
            index = tmp + 1;
        }
        string cur = s.substr(index, s.size() - index);
        data.push_back(cur);
        querylist.push_back(data);
    }

    // query 처리
    for (auto& q : querylist) {
        string key = q[0] + q[1] + q[2] + q[3];
        int score = stoi(q[4]);
        vector<int>& v = um[key];

        if (v.size() == 0) {
            answer.push_back(0);
        } else {
            int idx = lower_bound(v.begin(), v.end(), score) - v.begin();
            answer.push_back(v.size() - idx);
        }
    }

    return answer;
}
