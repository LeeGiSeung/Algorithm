#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    //1. genres에 들어있는 곡 장르의 재생수를 합쳐서 우선 순위 계산

    map<string, int> m;

    for (int i = 0; i < genres.size(); i++) {
        if (m.find(genres[i]) != m.end()) {
            m[genres[i]] += plays[i];
        }
        else {
            m.insert({ genres[i], plays[i] });
        }
    }

    vector<pair<string, int>> v(m.begin(), m.end());

    sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
        });
    //v = genres에 들어있는 곡 우선순위

    //2. 우선 순위대로 각 곡장르 index answer에 push back

    map<string, vector<pair<int, int>>> all_song;

    for (int i = 0; i < genres.size(); i++) {
        all_song[genres[i]].push_back({ plays[i], i });
    }

    for (auto i = v.begin(); i != v.end(); i++) {
        string a = i->first;
        vector<pair<int, int>> cur_song = all_song[a]; //정렬안된거임

        sort(cur_song.begin(), cur_song.end(), [](const auto& a, const auto& b) {
            return a.first > b.first; //재생수, index
        });

        answer.push_back(cur_song[0].second);
        if (cur_song.size() > 1) {
            answer.push_back(cur_song[1].second);
        }

    }

    return answer;
}

int main() {
    vector<string> v({ "classic", "pop", "classic", "classic", "pop" });
    vector<int> v1({ 500, 600, 150, 800, 2500 });

    solution(v, v1);

    return 0;
}