#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

vector<vector<int>> puzzleX;
vector<vector<int>> puzzleY;

vector<vector<bool>> puzzlemap(51, vector<bool>(51,false));
vector<vector<bool>> gameboardmap(51, vector<bool>(51,false));
int n;

bool solve(vector<int> &a, vector<int> &b){
    return a.size() > b.size();
}

void BFS_Puzzle(int x, int y, vector<vector<int>> table, int index){
    //puzzleX,puzzleY에 추가함
    
    queue<pair<int,int>> q;
    
    q.push({x,y});
    puzzlemap[x][y] = true;
    
    vector<int> px;
    vector<int> py;
    
     while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        px.push_back(x);
        py.push_back(y);
        
        for(int i = 0; i<4; i++){
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue; //범위 넘으면 아노딤
            if(puzzlemap[nx][ny]) continue; //이미 방문하면 안됨
            if(table[nx][ny] == 0) continue;
            puzzlemap[nx][ny] = true;
            q.push({nx,ny});
        }
     }
    
    puzzleX.push_back(px);
    puzzleY.push_back(py);
}

void NoWhite(int x, int y, vector<vector<int>> gameboard){
    //puzzleX,puzzleY에 추가함
    
    queue<pair<int,int>> q;
    
    q.push({x,y});
    gameboardmap[x][y] = true;
    
     while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i<4; i++){
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue; //범위 넘으면 아노딤
            if(gameboardmap[nx][ny]) continue; //이미 방문하면 안됨
            if(gameboard[nx][ny] == 1) continue;
            gameboardmap[nx][ny] = true;
            q.push({nx,ny});
        }
     }
}

int GAMEBOARD_BFS(int x, int y, vector<vector<int>> gameboard, int index){
    //퍼즐끼리 붙으면 안됨
    //퍼즐을 채웠을때 흰색 빈칸이 있으면 안됨
    
    //index에 맞게 숫자가 들어오고
    //이걸 4번 회전에서 맞춰보는 코드 만들어야함
    
    for(int i = 0; i<4; i++){ //회전
        //회전도 하고 상하 좌우 움직이기도 해야함
           
    }
    
    return 1;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = -1;

    n = game_board.size();
    
    int puzzleindex = 0;
    //table에서 퍼즐을 추출해야함    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(table[i][j] == 1 && !puzzlemap[i][j]){
                BFS_Puzzle(i,j,table,puzzleindex);
            }
        }
    }
    
    sort(puzzleX.begin(), puzzleX.end());
    sort(puzzleY.begin(), puzzleY.end());
    
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int whiteCount = 0;
            if(game_board[i][j] == 0){
                for(int z = 0; z<puzzleX.size(); z++){
                    //puzzle에 저장돼있는 칸 갯수로 커버가 되는건 칸 갯수와 같은거밖에없음
                    //크면 빈공간이 생기고, 작으면 안들어감 
                    //빈공간에는 퍼즐 두개를 넣어야하는데 이건 퍼즐 두개가 겹치니 안됨
                    if(whiteCount == 0 || whiteCount == puzzleX[z].size()){
                        whiteCount = GAMEBOARD_BFS(i,j,game_board,z);
                        
                        if(whiteCount == puzzleX[z].size()){
                            answer++; //만약 1트에 성공했으면 바로 answer추가하고 다음칸 찾으러 가야함
                            break;
                        }
                    }
                    else if(whiteCount < puzzleX[z].size()){
                        //크면 할 필요없음 다음꺼 찾기
                        continue;
                    }
                }
                
                //찾는 못찾든 무조건 이제 탐색할 이유없음
                NoWhite(i,j,game_board);
            }
        }
    }
    
    return answer;
}