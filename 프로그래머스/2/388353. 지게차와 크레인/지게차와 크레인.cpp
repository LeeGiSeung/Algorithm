#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;


int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n; int m;
void solve_air(queue<pair<int,int>> &q, vector<string> &board, char c){
    queue<pair<int,int>> tmp;
    bool check[52][52];
    memset(check, false, sizeof(check));
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx > n+1 || ny < 0 || ny > m+1) continue;
            if(check[nx][ny]) continue;

            if(board[nx][ny] == ' '){
                q.push({nx, ny});      // 공기만 BFS 확장
                check[nx][ny] = true;  // 방문 체크
            }
            else if(board[nx][ny] == c){
                board[nx][ny] = ' ';   // 삭제
                tmp.push({nx, ny});    // 삭제한 좌표만 tmp에 추가
                check[nx][ny] = true;
            }
            // 다른 컨테이너나 벽은 무시
        }
        
        // 현재 공기 위치는 계속 tmp에 유지
        tmp.push({x, y});
    }
    
    q = tmp; // 새로운 air 큐로 교체
}


void solve_count(vector<vector<pair<int,int>>> &count, vector<string> &board, char c){
    //c에 해당하는 count에 접근해서 board 지움
    for(int i = 0; i<count[c - 'A'].size(); i++){
        int x = count[c - 'A'][i].first;
        int y = count[c - 'A'][i].second;
        //cout<<x<<" "<<y<<" "<<c<<" 삭제"<<endl;
        board[x][y] = ' ';
    }
    
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    vector<vector<pair<int,int>>> count('Z' - 'A' + 1);
    
    queue<pair<int,int>> air; //바깥쪽
    
    //A  Board 외곽에서 들어가야함
    //AA 정보를 담아둔게 필요함
    
    

    n = storage.size();
    m = storage[0].size();
    vector<string> board(n + 2, string(m + 2, ' '));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i + 1][j + 1] = storage[i][j];
            count[storage[i][j] - 'A'].push_back({i + 1, j + 1});
        }
    }
    
    for (int i = 0; i < n + 2; i++) {
        air.push({i, 0});
        air.push({i, m + 1});
    }
    for (int j = 0; j < m + 2; j++) {
        air.push({0, j});
        air.push({n + 1, j});
    }
    

    //접근이 가능한 해당 종류의 컨테이너를 모두 꺼낸다
    //4면 중 적어도 1면이 창고 외부와 연결된 컨테이너
    //이때 모든 요청을 순서대로 완료한 후 남은 컨테이너의 수를 return
    
    
    //air 공기 위치 : 접근이 가능한 해당 종류의 컨테이너
    //count : 해당하는 모든 컨테이너
    
    for(string s : requests){
        if(s.size() == 1){
            solve_air(air, board, s[0]);
        }
        else if(s.size() == 2){
            solve_count(count, board, s[0]);
        }
    }
    
    //board에 존재하는 모든 컨테이너의 갯수를 업데이트함
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(board[i][j] != ' ') answer++;
        }
    }
    
    return answer;
}