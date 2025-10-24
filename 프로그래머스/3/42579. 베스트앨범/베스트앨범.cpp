#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

map<string, int> music; //노래 play 합친거
map<string, vector<pair<int,int>>> musicrank;

bool st(pair<int,int> &a, pair<int,int> &b){
    if(a.first != b.first)
        return a.first > b.first;
    else
        return a.second < b.second;
}

bool stt(pair<string, int> &a, pair<string, int> &b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    //장르 정렬
    for(int i = 0; i<genres.size(); i++){
        //i : 고유 번호
        string mus = genres[i];
        int play = plays[i];
        music[mus] += play;
        
        musicrank[mus].push_back({play,i});
        
    }
    vector<pair<string,int>> musiclist;
    
    for(auto a : music){
        musiclist.push_back({a.first, a.second});
    }
    
    sort(musiclist.begin(), musiclist.end(), stt);
    
    //music 안에 장르 정렬이 되어있음
    //장르 내 노래 정렬
    
    for(auto a : musicrank){
        sort(musicrank[a.first].begin(), musicrank[a.first].end(), st);
    }
    
    //map<string, vector<pair<int,int>>> musicrank;
    for(pair<string,int> a : musiclist){
        int count = 0;
        for(pair<int,int> v: musicrank[a.first]){
            count++;
            answer.push_back(v.second);
            if(count == 2) break;
        }
    }

    return answer;
}