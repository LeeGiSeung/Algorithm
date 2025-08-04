#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int cnt[360001];

vector<vector<int>> v;
int max_count = 0;
bool sv(const vector<int> &a, const vector<int> &b){
    if(a[0] != b[0]) return a[0] < b[0];
    else return a[1] < b[1];
}

int str_to_int(string s){
    int cur = 0;
    
    cur += stoi(s.substr(0,2)) * 3600; //시간
    cur += stoi(s.substr(3,2)) * 60; //분
    cur += stoi(s.substr(6,2));
    
    return cur;
}

string int_to_str(int num){
    string s;
    int hour = num / 3600;
    num %= 3600;
    int min = num / 60;
    int sec = num % 60;

    if (hour < 10) s += '0';
    s += to_string(hour);
    s += ':';
    if (min < 10) s += '0';
    s += to_string(min);
    s += ':';
    if (sec < 10) s += '0';
    s += to_string(sec);

    return s;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    if(play_time == adv_time){
        return "00:00:00";
    }
    string answer = "";
    int playtime = 0;
    int advtime = 0;
    
    playtime = str_to_int(play_time);
    advtime = str_to_int(adv_time);
    
    queue<int> q;
    for(string cs : logs){
        int s = str_to_int(cs.substr(0,8));
        int e = str_to_int(cs.substr(9,8));
        
        for(int i = s; i<e; i++){
            cnt[i] += 1;
        }
    }
    
    int index = 0;
    long long cur = 0;
    long long result = 0;
    
    for(int i = 0; i<advtime; i++){
        cur += cnt[i];
        q.push(cnt[i]);
    }
    
    result = cur;
    
    for(int i = advtime; i<playtime; i++){
        cur -= q.front();
        q.pop();
        cur += cnt[i];
        q.push(cnt[i]);
        
        if(cur > result){
            result = cur;
            index = i - advtime + 1;
        }
    }
    
    answer = int_to_str(index);
    
    return answer;
}