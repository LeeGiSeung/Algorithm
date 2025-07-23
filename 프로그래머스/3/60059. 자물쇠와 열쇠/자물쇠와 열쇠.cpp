#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int ct = 0;
int k,l,b;

bool check(vector<vector<int>> key, vector<vector<int>> board , int x, int y){
    //상하좌우 움직여서 틈 맞추기
    bool asr = true;
    for(int i = 0; i<k; i++){
        for(int j = 0; j<k; j++){
            board[i+ x][j + y] += key[i][j];
        }
    }
    
    for(int i = 0; i < l; i++){
        for(int j = 0; j < l; j++){
            if(board[i + k - 1][j + k - 1] != 1){
                // board 원상 복구
                for(int p = 0; p < k; p++){
                    for(int q = 0; q < k; q++){
                        board[p + x][q + y] -= key[p][q];
                    }
                }
                return false;
            }
        }
    }
    
    for(int i = 0; i<k; i++){
        for(int j = 0; j<k; j++){
            board[i + x][j + y] -= key[i][j];
        }
    }
    
    return asr;
}

void rotate(vector<vector<int>> &key){
    vector<vector<int>> temp = key;
    
    for(int i = 0; i<key.size(); i++){
        for(int j = 0; j<key.size(); j++){
            temp[i][j] = key[key.size() - 1 - j][i];
        }
    }
    
    key = temp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    k = key.size();
    l = lock.size();
    b = 2 * (k - 1) + l;
    vector<vector<int>> board(b, vector<int>(b, 0));
    
    // 가운데에 lock 영역 두기 (3번)
    for(int i=0; i<l; ++i) {
        for(int j=0; j<l; ++j) {
            board[i+k-1][j+k-1] = lock[i][j];
        }
    }
    
    for(int i = 0; i<4; i++){ //key를 90도씩 회전
        //1. 회전
        rotate(key);
        
        //2. 키를 상하좌우 움직여서 틈 맞추기
        //사이즈는 lock에 1한칸만 걸쳐도 됨
        for(int x = 0; x<= b-k; x++){
            for(int y = 0; y<= b-k; y++){
                if(check(key, board,x,y)){
                    return true;    
                }
            }
        }
    }
    
    return answer;
}