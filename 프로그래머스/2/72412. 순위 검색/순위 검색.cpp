#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

map<string ,vector<int>> m;

void makemap(vector<string> &infolist, int score){
    // 2진수로 0000 0001 0010 0011 : 1이 - 들어가는 key임임
    for(int i = 1; i<=16; i++){
        string key = "";
        int num = i;
        for(int j = 0; j<4; j++){ //0~3까지 반복문 돌려서 2진수 계산
            if(num % 2 == 0) key += infolist[j];
            else key += "-";
            num /= 2;
        }
        m[key].push_back(score);
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

    //infolist 에 들어있는 문자열을 이용해서 key를 만들어야함
    //이대로 탐색하면 무조건 시간 초과나기 때문
    for(int i = 0; i<infolist.size(); i++){
        makemap(infolist[i], stoi(infolist[i][4]));
    }
    
    for(auto &p : m){
        sort(p.second.begin(), p.second.end(), greater<int>());
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

    for(int i = 0; i<querylist.size(); i++){
        string key = querylist[i][0] + querylist[i][1] +querylist[i][2] +querylist[i][3];
        int score = stoi(querylist[i][4]);
        
        if(m[key].size() == 0) answer.push_back(0);
        else{
            int index = 0;
            for(int cur : m[key]){
                if(cur >= score) index++;
                else break;
            }
            answer.push_back(index);
        }
    }
    

    return answer;
}
