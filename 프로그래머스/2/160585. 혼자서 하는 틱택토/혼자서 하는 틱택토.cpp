#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

bool check[3][3];

bool solve(vector<pair<int,int>> &olist){
    
    memset(check, false, sizeof(check));
    
    for(pair<int,int> p : olist){
        check[p.first][p.second] = true;
    }
    
    //가로
    for(int i = 0; i<3; i++){
        if(check[i][0] && check[i][1] && check[i][2]) return true;
    }
    
    //세로
    for(int i = 0; i<3; i++){
        if(check[0][i] && check[1][i] && check[2][i]) return true;
    }
    
    //대각선
    if(check[0][0] && check[1][1] && check[2][2]) return true;
    if(check[0][2] && check[1][1] && check[2][0]) return true;
    
    return false;
}

int solution(vector<string> board) {
    int answer = 1;
    
    // 9칸이 모두 차서 더 이상 표시를 할 수 없는 경우에는 무승부로 게임이 종료됩니다.
    // 이 게임판이 규칙을 지켜서 틱택토를 진행했을 때 나올 수 있는 게임 상황이면 1 아니면 0
    
    int o = 0;
    int x = 0;
    
    vector<pair<int,int>> olist;
    vector<pair<int,int>> xlist;
    
    for(int i = 0; i<board.size(); i++){
        for(int j = 0; j<board[i].size(); j++){
            if(board[i][j] == 'O'){
                olist.push_back({i,j});
                o++;
            } 
            else if(board[i][j] == 'X'){
                xlist.push_back({i,j});
                x++;
            } 
        }
    }
    
    if(x > o || abs(x - o) >= 2) return 0; //후공인 x가 더 많거나 두개 차이가 2이상이면 가능하지않음
    if(x < 3 && o < 3) return 1; //틱택토 아예 안되는거면 그냥 reutrn 하면됨
    
    //〉	["OOO", "...", "XXX"] O 틱택토가 되는데 X랑 갯수가 같은게 말이안됨
    if(solve(olist) && solve(xlist)) return 0;
    else if(solve(olist)){
        if(o != x + 1) return 0;
    }
    else if(solve(xlist)){
        if(o != x) return 0;
    }
    
    
    return answer;
}