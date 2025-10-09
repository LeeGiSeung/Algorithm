#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;

map<int, vector<pair<int,int>>> list, block; //list : 지워야할 목록들이 들어있음
vector<vector<int>> board;
vector<bool> check(201, false);
//직사각형은 무조건 
//2x3
int dx1[6] = {0,0,0,1,1,1};
int dy1[6] = {0,1,2,0,1,2};

//3x2
int dx2[6] = {0,1,2,0,1,2};
int dy2[6] = {0,0,0,1,1,1};

bool solve(int a, vector<pair<int,int>> tmp){
    for(auto [x,y] : tmp){
        while(x >= 0){
            if(board[x--][y] != 0) return false;
        }
    }
    
    for(auto [x,y] : list[a]){
        board[x][y] = 0;
    }
    
    return true;
}

int solution(vector<vector<int>> _board) {
    int answer = 0;
    board = _board;
    for(int i = 0; i<board.size(); i++)
        for(int j = 0; j<board[0].size(); j++)
            if(board[i][j] != 0) list[board[i][j]].push_back({i,j});
    int n = board.size();
    int m = board[0].size();
    //2x3
    for(auto [v, point] : list){
        for(int i = 0; i<n - 1; i++){
            for(int j = 0; j<m - 2; j++){
                vector<pair<int,int>> tmp;
                int cnt = 0;
                for(int d = 0; d<6; d++){
                    int nx = dx1[d] + i;
                    int ny = dy1[d] + j;
                    if(board[nx][ny] == v) cnt++;
                    else tmp.push_back({nx,ny});
                }
                if(cnt == 4){ 
                    block[v] = tmp;
                }
            }
        }
    }
    
    //3x2
    for(auto [v, point] : list){
        for(int i = 0; i<n - 2; i++){
            for(int j = 0; j<m - 1; j++){
                vector<pair<int,int>> tmp;
                int cnt = 0;
                for(int d = 0; d<6; d++){
                    int nx = dx2[d] + i;
                    int ny = dy2[d] + j;
                    if(board[nx][ny] == v) cnt++;
                    else tmp.push_back({nx,ny});
                }
                if(cnt == 4){
                    block[v] = tmp;
                }
            }
        }
    }
    
    //block에 현재 지워야 하는 빈칸들이 들어있음
    bool flag = true;
    while(flag){
        flag = false;
        for(auto [a,b] : block){
            if(check[a]) continue;
            if(solve(a,b)){
                check[a] = true;
                answer++;
                flag = true;
            }
        }
    }
    
    return answer;
}