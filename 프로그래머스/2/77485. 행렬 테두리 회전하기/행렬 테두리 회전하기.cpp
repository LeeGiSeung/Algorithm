#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int board[101][101];

void turn(int x1, int y1, int x2, int y2, vector<int> &answer){
    //테두리에 있는 숫자들을 시계 방향으로 회전
    //위
    int tmpmin = 1e8;
    int tmp = board[x1][y1];
    for(int i = x1; i<x2; i++){
        tmpmin = min(tmpmin, board[i][y1]);
        board[i][y1] = board[i + 1][y1];
    }

    for(int i = y1; i<y2; i++){
        tmpmin = min(tmpmin, board[x2][i]);
        board[x2][i] = board[x2][i + 1];
    }
    
    for(int i = x2; i > x1; i--){
        tmpmin = min(tmpmin, board[i][y2]);
        board[i][y2] = board[i - 1][y2];
    }
    
    for(int i = y2; i > y1; i--){
        tmpmin = min(tmpmin, board[x1][i]);
        board[x1][i] = board[x1][i - 1];
    }
    
    board[x1][y1 + 1] = tmp;
    
    answer.push_back(tmpmin);
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    //테두리에 있는 숫자들을 시계 방향으로 회전
    int a = 1;
    for(int i = 1; i<= rows; i++){
        for(int j = 1; j<= columns; j++){
            board[i][j] = a;
            a++;
        }
    }
    
    for(int i = 0; i<queries.size(); i++){
        int x1 = queries[i][0];
        int y1 = queries[i][1];
        int x2 = queries[i][2];
        int y2 = queries[i][3];
        turn(x1,y1,x2,y2,answer);
    }
    
    return answer;
}