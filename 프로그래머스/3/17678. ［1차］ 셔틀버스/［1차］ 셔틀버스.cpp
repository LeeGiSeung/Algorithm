#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> v;

string make_str(int ti){
    string re;

    int hour = ti / 60;
    int minute = ti % 60;

    if (hour < 10) re += "0";
    re += to_string(hour);
    re += ":";

    if (minute < 10) re += "0";
    re += to_string(minute);

    return re;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer;
    vector<int> v;

    for(string time : timetable){
        int hour = stoi(time.substr(0, 2));
        int minute = stoi(time.substr(3, 2));
        v.push_back(hour * 60 + minute);
    }

    sort(v.begin(), v.end());
    
    int bustime = 540;
    int idx = 0;
    
    for(int i = 0; i<n; i++){
        int count = 0;
        
        while(idx < timetable.size() && v[idx] <= bustime && count < m){
            idx++;
            count++;
        }
        
        if(i == n - 1){
            if(count < m){
                return make_str(bustime);
            }
            else{
                return make_str(v[idx - 1] - 1);
            }
        }
        bustime += t;
    }
    
    return answer;
}