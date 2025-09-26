#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

int board[101][101];

void clearboard(){
    memset(board, 0, sizeof(board));
}

struct Data{
    int cx; 
    int cy;
    int goal;
    bool finish;
};

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    int n = routes.size(); //n 로봇 갯수
    
    vector<Data> robot;
    
    for(int i = 0; i<n; i++){
        int startpoint = routes[i][0];
        int cx = points[startpoint - 1][0];
        int cy = points[startpoint - 1][1];
        board[cx][cy]++;
        robot.push_back({cx, cy, 1, false});
        //cx에서 시작해서 cy로 다음 목적지는 1번째 인덱스고 현재 성공은 false
    }
    
    for(int i = 1; i<101; i++){
        for(int j = 1; j<101; j++){
            if(board[i][j] > 1) answer += 1;
        }
    }
    
    int time = 1;
    /*
    if(n != 4) return answer;
    */
    while(true){
        bool allfinish = true;
        clearboard();
        /*
        if(n == 4)
        cout<<time<<" 시간"<<endl;
        time++;
        */
        for(int i = 0; i<n; i++){
            if(robot[i].finish) continue;
            
            int &goal = robot[i].goal; //goal routes[i][goal] 에 접근할 값
            int goalpoint = routes[i][goal];
            goalpoint--;
            
            int &cx = robot[i].cx;
            int &cy = robot[i].cy;
            int gx = points[goalpoint][0];
            int gy = points[goalpoint][1];
            
            /*
            if(n == 4)
            cout<<i + 1<<" 번째 로봇의 위치"<<cx<<" "<<cy<<"목적지 " <<gx<<" "<<gy<<endl;
            */
            if(abs(cx - gx) != 0){
                if(cx > gx) cx--;
                else cx++;
            }
            else{
                if(cy > gy) cy--;
                else cy++;
            }
            
            board[cx][cy]++;
            allfinish = false; //이동했다는건 아직 끝난게 아님
            if(cx == gx && cy == gy){
                goal++;
                /*
                if(n == 4)
                cout<<i + 1<<" 번째 로봇 도착"<<cx<<" "<<cy<<endl;
                */
                if(goal > routes[i].size() - 1) robot[i].finish = true;
            }
        }
        
        if(allfinish) break; //전부 다 돼있으면 continue;
        
        for(int i = 1; i<101; i++){
            for(int j = 1; j<101; j++){
                if(board[i][j] > 1) answer += 1;
            }
        }
    }
    
    return answer;
}