#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
bool check[31][31];
int answer = 0;

void deleteblock(int m, int n, vector<string> &board){
    for(int i = 0; i < m; i++){
        for(int j = 0; j<n; j++){
            if(check[i][j]){
                board[i][j] = ' ';
                answer++;
            } 
        }
    }  
}

void downblock(int i, int j,int m, int n, vector<string> &board){
    //i j위치 블럭을 올려야함
    //0 이하로 넘어가면 안됨
    while(i - 1 >= 0 && board[i - 1][j] != ' '){ //i가 m이하이고 i - 1 j가 false일때
        //dfs로 그냥 넘거야할듯?
        board[i][j] = board[i - 1][j]; //그냥 덮어 씌움
        board[i - 1][j] = ' ';
        i--; //다음칸으로 내림
    }
}

bool checkdel(int i, int j,int m, int n, vector<string>& board){
    //오른쪽, 아래, 오른쪽아래 대각선
    if(i + 1 >= m || j + 1 >= n) return false; //둘중하나라도 기본 크기 넘으면 return임
    char c = board[i][j]; //기준 문자
    if(c == board[i + 1][j] && c == board[i + 1][j + 1] && c == board[i][j + 1]){
        check[i][j] = true;
        check[i + 1][j] = true;
        check[i + 1][j + 1] = true;
        check[i][j + 1] = true;
        //4개 삭제 처리
        //cout<<c<<" 감지"<<endl;
        return true;
    }
    return false;
}

bool dfs(int m, int n, vector<string>& board){
    //삭제하기
    bool ch = false;
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j<n; j++){
            if(board[i][j] == ' ') continue; //빈칸은 하면안됨
            if(checkdel(i,j,m,n,board)){
                ch = true;
            };
        }
    }
    
    //check true인거 삭제하기
    deleteblock(m, n, board);
    
    //내리기
    //check가 false인건 안지워진 것들 이것들을 내리면됨
    for(int i = 0; i < m; i++){
        for(int j = 0; j<n; j++){
            if(board[i][j] == ' ')
                downblock(i,j,m,n,board);
        }
    }
    memset(check, false, sizeof(check));
    
    //for(int i = 0; i < m; i++){
        //for(int j = 0; j<n; j++){
            //cout<<board[i][j]<<" ";
        //}
        //cout<<endl;
    //}
    //cout<<endl;
    
    return ch;
}

int solution(int m, int n, vector<string> board) {
    
    memset(check,false,sizeof(check));
    
    //for(int i = 0; i < m; i++){
        //for(int j = 0; j<n; j++){
            //cout<<board[i][j]<<" ";
        //}
        //cout<<endl;
    //}
    //cout<<endl;
    
    
    while(dfs(m,n,board));
    
        
    
    return answer;
}