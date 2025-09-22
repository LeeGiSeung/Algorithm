#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <map>
#include <set>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

struct Data{
    int x;
    int y;
};

bool check[501][501];
int board[501][501];
map<int,int> m;
void bfs(int x, int y, vector<vector<int>> &land, int oilnum){
    
    queue<Data> q;
    q.push({x,y});
    int oil = 1;
    check[x][y] = true;
    board[x][y] = oilnum;
    while(!q.empty()){
        
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        
        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= land.size() || ny < 0 || ny >= land[0].size()) continue;
            if(check[nx][ny]) continue;
            if(land[nx][ny] == 0) continue;
            check[nx][ny] = true;
            oil++;
            
            board[nx][ny] = oilnum;
            
            q.push({nx,ny});
        } 
    }

    m[oilnum] = oil;
    
    return;
    
}

int dig(int y, int under){
    int answer = 0;
    set<int> seen; // 이미 더한 덩어리 번호 저장
    
    for(int x = 0; x<under; x++){
        int id = board[x][y];
        if(id == 0) continue;
        if(seen.find(id) != seen.end()) continue; // 이미 더했으면 스킵
        answer += m[id];
        seen.insert(id);
    }
    return answer;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    memset(board, 0, sizeof(board));
    memset(check, false, sizeof(check));
    int oilnum = 1;
    for(int i = 0; i<land.size(); i++){
        for(int j = 0; j<land[0].size(); j++){
            if(land[i][j] != 1 || board[i][j] != 0) continue; //석유가 아니거나 이미 탐사가 끝난부분은 더이상 x
            bfs(i, j, land, oilnum);
            oilnum++;
        }
    }
    
    /*
    for(int i = 0; i<land.size(); i++){
        for(int j = 0; j<land[0].size(); j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    */

    for(int i = 0; i<land[0].size(); i++){
        answer = max(answer, dig(i, land.size()));
    }
    
    //당신이 시추관을 수직으로 단 하나만 뚫을 수 있을 때
    
    return answer;
}