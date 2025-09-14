#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Data {
    int playtime;   // 실제 재생 시간
    int order;      // 입력 순서
    string title;   // 곡 제목
};

bool cmp(Data &a, Data &b) {
    if (a.playtime != b.playtime) return a.playtime > b.playtime;
    return a.order < b.order;  // 입력된 순서가 더 빠른 곡 우선
}

// 멜로디 문자열 치환 (C#, D# 같은 음을 소문자로 바꿔서 한 글자로 취급)
string convert(string s) {
    vector<pair<string, string>> list = {
        {"C#", "c"}, {"D#", "d"}, {"F#", "f"},
        {"G#", "g"}, {"A#", "a"}, {"B#", "b"}, {"E#", "e"}
    };
    for (auto &p : list) {
        size_t pos = 0;
        while ((pos = s.find(p.first, pos)) != string::npos) {
            s.replace(pos, p.first.size(), p.second);
        }
    }
    return s;
}

int getTime(string s, string e) {
    int sh = stoi(s.substr(0, 2)), sm = stoi(s.substr(3, 2));
    int eh = stoi(e.substr(0, 2)), em = stoi(e.substr(3, 2));
    return (eh * 60 + em) - (sh * 60 + sm);
}

string solution(string m, vector<string> musicinfos) {
    m = convert(m);
    vector<Data> answer_list;

    for (int i = 0; i < musicinfos.size(); i++) {
        string cur = musicinfos[i];
        vector<string> info;
        int index = 0;
        while (index < cur.size()) {
            int pos = cur.find(',', index);
            if (pos == string::npos) {
                info.push_back(cur.substr(index));
                break;
            }
            info.push_back(cur.substr(index, pos - index));
            index = pos + 1;
        }

        int playtime = getTime(info[0], info[1]);
        string melody = convert(info[3]);

        // playtime에 맞게 멜로디 늘리기
        string full = "";
        for (int j = 0; j < playtime; j++) {
            full += melody[j % melody.size()];
        }

        if (full.find(m) != string::npos) {
            answer_list.push_back({playtime, i, info[2]});
        }
    }

    if (answer_list.empty()) return "(None)";

    sort(answer_list.begin(), answer_list.end(), cmp);
    return answer_list[0].title;
}
