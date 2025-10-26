#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <map>
using namespace std;

bool st(pair<int,int> &a, pair<int,int> &b){
    if(a.second - a.first != b.second - b.first){
        return a.second - a.first < b.second - b.first;
    }
    else{
        //같으면 시작점 작은 순서로
        return a.first < b.first;
    }
}

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    map<string,int> mlist;
    //모든 보석을 포함하는 가장 짧은 구간
    //가장 짧은 구간의 시작 진열대 번호와 끝 진열대 번호
    int left = 0;
    int right = 0;
    
    for(string s : gems) mlist[s]++;
         
    int msize = mlist.size(); //보석 종류 수
    
    map<string,int> m;
    vector<pair<int,int>> answerlist;
    
    
    while (true) {
        if (m.size() == msize) {
            // 정답 후보
            answerlist.push_back({left + 1, right}); // +1은 문제 인덱스 보정용
            m[gems[left]]--;
            if (m[gems[left]] == 0)
                m.erase(gems[left]);
            left++;
        } 
        else {
            if (right == gems.size()) break;
            m[gems[right]]++;
            right++;
        }
    }
    
    sort(answerlist.begin(), answerlist.end(), st);
    
    answer[0] = answerlist[0].first;
    answer[1] = answerlist[0].second;
    
    return answer;
}