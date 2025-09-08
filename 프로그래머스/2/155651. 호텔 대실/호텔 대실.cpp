#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

bool solve(const vector<int> &a, const vector<int> &b){
    if(a[0] != b[0]){
        //시작 시간이 더 빠르면
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    vector<vector<int>> booktime;
    
    //입실 시간을 기준으로 sort
    for(vector<string> s : book_time){
        int startmin = 0;
        int endmin = 0;
        startmin += stoi(s[0].substr(0,2)) * 60;
        startmin += stoi(s[0].substr(3,2));
        
        endmin += stoi(s[1].substr(0,2)) * 60; //호텔 퇴실 시간
        endmin += stoi(s[1].substr(3,2));
        
        vector<int> v;
        v.push_back(startmin);
        v.push_back(endmin);
        booktime.push_back(v);
    }
    
    sort(booktime.begin(), booktime.end(), solve);
    
    for(int i = 0; i<booktime.size(); i++){
        int stmin = booktime[i][0];
        int edmin = booktime[i][1];
        //pq는 여유 회의실
        if(pq.empty()){ //지금 여유회의실이 없다는거 이러면 그냥 바로 추가해야함
            pq.push(edmin); //청소 시간까지 추가해야함
            answer++; //회의실 추가했으니 정답은 늘려야함
        }
        else{
            //10분간 청소를 하고 
            if(pq.top() + 10> stmin){ //회의실 끝나는 시간이 지금 시작시간 보다 클경우
                //이러면 예비 회이실이 없는거니까 회의실 새로 만들어야함
                pq.push(edmin);
                answer++;
            }
            else{//회의실 끝나는 시간이 지금 시작시간 보다 작을경우
                //회의가 끝났으니까 들어갈 수 있음
                pq.push(edmin);
                pq.pop();
                //추과 회의실은 안생김
            }
        }
        
    }
    
    return answer;
}