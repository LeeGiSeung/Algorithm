#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    map<string, int> m;

    for (int i = 0; i < cities.size(); i++) {
        string a;
        for (int j = 0; j < cities[i].size(); j++) {
            a += tolower(cities[i][j]);
        }
        cities[i] = a;
    }

    for (int i = 0; i < cities.size(); i++) { //i = page

        if (m.find(cities[i]) != m.end()) { //존재하면
            auto a = m.find(cities[i]);
            a->second = i; //페이지 갱신
            answer += 1;
        }
        else {
            answer += 5;

            //존재하지 않으면 넣어야함
            if (m.size() < cacheSize) { //아직 페이지가 3개 이상 안올라가 있을 경우 그냥 넣음
                m.insert({ cities[i], i });
            }
            else {
                int a = 100001;
                auto least = m.begin();
                //빈 자리가 없으면 가장 오래된 페이지 교환
                for (auto j = m.begin(); j != m.end(); j++) {
                    //가장 오래된 페이지 찾기
                    if (j->second < a) {
                        least = j; //가장 오래된것
                        a = j->second;
                    }
                }
                if (cacheSize != 0) {
                    m.erase(least);
                    m.insert({ cities[i], i });
                }
            }
        }
    }

    return answer;
}

int main() {

    vector<string> a = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };

    solution(0,a);
}