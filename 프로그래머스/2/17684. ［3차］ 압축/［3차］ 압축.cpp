#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    vector<string> abc;
    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (char c : s) {
        abc.push_back(string(1, c)); // 한 글자를 string으로 변환해서 넣음
    }

    map<string, int> m;
    int index_count = 1;
    for (int i = 0; i < abc.size(); i++) {
        m[abc[i]] += index_count;
        index_count++;
    }
    string cur = "";
    for(int i = 0; i<msg.size(); i++){
        cur += msg[i];
        if(m[cur] == 0){
            m[cur] = index_count++;
            answer.push_back(m[cur.substr(0, cur.size() - 1)]);
            cur = "";
            i--;
        }
    }
    
    answer.push_back(m[cur]);
    
    return answer;
}