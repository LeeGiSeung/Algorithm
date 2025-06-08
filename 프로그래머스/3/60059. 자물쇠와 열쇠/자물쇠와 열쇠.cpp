#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int k,l,limit;

void turn(vector<vector<int>> &in){
    int s = in.size();
    vector<vector<int>> v(s, vector<int>(s));
    for(int i = 0; i<s; i++){
        for(int j = 0; j<s; j++){
           v[i][j] = in[s - j - 1][i];
        }
    }
    in = v;
}

bool check(vector<vector<int>> &board, vector<vector<int>> &key, int x, int y){
    bool check = true;
    
    //x,y index 위치임
    
    for(int i = 0; i<key.size(); i++){
        for(int j = 0; j<key.size(); j++){
            board[i + x][j + y] += key[i][j]; 
        }
    }
    
    for(int i = 0; i<l; i++){
        for(int j = 0; j<l; j++){
            if(board[i + k - 1][j + k - 1] != 1){
                check = false;
            }; 
        }
    }
    
    for(int i = 0; i<key.size(); i++){
        for(int j = 0; j<key.size(); j++){
            board[i + x][j + y] -= key[i][j]; //다시 빼줌
        }
    }
    
    return check;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    k = key.size();
    l = lock.size();
    limit = 2*(k-1) + l;
    // 열쇠로 자물쇠를 열수 있으면 true를, 열 수 없으면 false
        
    vector<vector<int>> board(limit, vector<int>(limit, 0));
    
    //보드에 lock 배열
    for(int i = 0; i<l; i++){
        for(int j = 0; j<l; j++){
            board[i + k - 1][j + k - 1] = lock[i][j]; 
        }
    }
    
    for(int z = 0; z<4; z++){ //90도씩 4번 회전
        //index는 board 전체 크기에서 key 사이즈를 뺀만큼까지 key를 놓을 수 있음
        for(int i = 0; i<=limit-k; i++){
            for(int j = 0; j<=limit-k; j++){
                if(check(board, key, i,j)) return true; //만약 정답되면 그냥 true return
            }
        }
        turn(key);
    }
    
    return answer;
}