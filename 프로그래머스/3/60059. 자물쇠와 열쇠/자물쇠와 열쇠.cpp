#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int k,l,b;

void turn(vector<vector<int>> &key){
    vector<vector<int>> v(k, vector<int>(k,0));
    
    for(int i = 0; i<k; i++){
        for(int j = 0; j<k; j++){
            v[i][j] = key[k - j - 1][i];
        }
    }
    
    key = v;
    
}

bool check(vector<vector<int>> &board, vector<vector<int>> &key, int x, int y){
    bool ch = true;
    
    for(int i = 0; i<k; i++){
        for(int j = 0; j<k; j++){
            board[i + x][j + y] += key[i][j];
        }
    }
    
    for(int i = 0; i<l; i++){
        for(int j = 0; j<l; j++){
            if(board[i + k - 1][j + k - 1] != 1){
                ch = false;
            }
        }
    }
    
    for(int i = 0; i<k; i++){
        for(int j = 0; j<k; j++){
            board[i + x][j + y] -= key[i][j];
        }
    }
    return ch;   
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
 
    k = key.size();
    l = lock.size();
    b = (k-1) * 2 + l; //전체 보드 크기
    
    vector<vector<int>> board(b, vector<int>(b,0)); //board 설정
    
    //보드에 자물쇠 배치
    for(int i = 0; i<l; i++){
        for(int j = 0; j<l; j++){
            board[i + k - 1][j + k - 1] = lock[i][j];
        }
    }  
    
    for(int t = 0; t<4; t++){
        for(int i = 0; i<= b - k; i++){
            for(int j = 0; j<=b - k; j++){
                if(check(board, key, i,j)) return true;;
            }
        }
        turn(key);
    }
    
    return answer;
}