#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

struct Data{
    int normal;
    int outlink;
    vector<string> matching; //해당 주소로 연결된 놈들 추가
};
//a -> b

//b -> c

//b -> a
//c -> a

bool st(pair<double, int> &a, pair<double, int> &b){
    if(a.first != b.first){
        return a.first > b.first;
    }
    else return a.second < b.second;
}

int solution(string word, vector<string> pages) {
    int answer = 0;
    
    for(int i = 0; i<word.size(); i++){
        word[i] = tolower(word[i]);
    }
    
    map<string, Data> data; //content 주소, index
    vector<pair<double,int>> score; //최종 점수
    vector<string> content(pages.size()); //각 pages별 가지고있는 content 주소
    
    for(int i = 0; i<pages.size(); i++){
        string c1 = "<meta property=\"og:url\" content=\"https://";
        string c2 = "\"";
        int cut1 = pages[i].find(c1);
        if (cut1 == string::npos) continue;
        cut1 += c1.size();

        int cut2 = pages[i].find("\"", cut1); // cut1 이후부터 탐색
        if (cut2 == string::npos) continue;

        content[i] = pages[i].substr(cut1, cut2 - cut1);
    }
    
    //기본 점수 구하기
    for(int i = 0; i<pages.size(); i++){
        string str = "";
        string s = pages[i];
        vector<string> list;
        int idx = 0;
        while(idx < s.size()){
            char c = tolower(s[idx]);
            if(c >= 'a' && c <= 'z'){ //띄어쓰기, 특수문자 가아닐때 더함
                str += c;
            }
            else{
                list.push_back(str);
                str = "";
            }
            idx++;
        }
        if (!str.empty()) list.push_back(str);
        for(int j = 0; j<list.size(); j++){
            if(list[j] == word){
                data[content[i]].normal += 1;
            }
        }
    }
    
    //외부 링크 수 구하기
    for(int i = 0; i<pages.size(); i++){
        string c1 = "<a href=\"https://";
        string c2 = "\">";
        int cut1 = 0;
        while (true) {
            cut1 = pages[i].find(c1, cut1);
            if (cut1 == string::npos) break;
            cut1 += c1.size();
            int cut2 = pages[i].find(c2, cut1);
            if (cut2 == string::npos) break;
            string outlink = pages[i].substr(cut1, cut2 - cut1);
            data[content[i]].outlink++;
            if (data.find(outlink) != data.end()) {
                data[outlink].matching.push_back(content[i]);
            }
        }
    }
    /*
    struct Data{
    int normal;
    int outlink;
    vector<string> matching; //해당 주소로 연결된 놈들 추가
    };
    
    map<string, Data> data; //각 주소별 데이터
    vector<pair<int,int>> score; //최종 점수
    vector<string> content(pages.size()); //각 pages별 가지고있는 content 주소
    */
    for(int i = 0; i<pages.size(); i++){
        double curscore = 0;
        //식 : 기본점수 + 자신에 (연결된 홈페이지 기본점수) / (연결된 홈페이지 링크수)
        curscore += data[content[i]].normal; //
        for(int j = 0; j<data[content[i]].matching.size(); j++){
            string out = data[content[i]].matching[j];
            curscore += (double)data[out].normal / (double)data[out].outlink;
        }
        score.push_back({curscore, i});
    }
    
    sort(score.begin(), score.end(), st);
    
    answer = score[0].second;
    
    return answer;
}