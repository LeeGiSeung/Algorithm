#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

struct Data{
    int x;
    int y;
    int count;
    string s;
};
//d l r u 순으로 이동
int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};
string direction[4] = {"d","l","r","u"};

void dfs(int n, int m, int x, int y, string &s, int r, int c, int k, int count, bool &dfsoff, string &st){
    //cout<<s<<endl;
    if(dfsoff) return; //끝났으면 dfs 종료
    
    if(x == r && y == c && count == k){
        dfsoff = true;
        s = st;
        return;
    }
    
    if(abs(x - r) + abs(y - c) > k - count) return; //남은게 더 멀면
    
    for(int i = 0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx > 0 && nx <=n && ny > 0 && ny <=m){ //범위 안에있고
            if(count + 1 <= k){ //가능한 횟수일때
                st += direction[i];
                dfs(n,m,nx,ny,s,r,c,k,count + 1, dfsoff, st);
                st.erase(st.size() - 1);
            }
        }
        
    }
    
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    int distance = abs(x - r) + abs(y - c);
    if((k - distance) % 2 != 0 || distance > k){
        answer = "impossible";
        return answer;
    }
    
    bool check = false;
    string st;
    dfs(n,m,x,y,answer,r,c,k,0,check,st);
    
    if(!check) answer = "impossible";
    
    //x y에서 출발해 r c로 이동
    //격자 바깥으로는 x
    //x y에서 r c까지의 거리가 총 k 여야한다.
    //x y와 r c를 포함해 같은 격자를 두번 이상 방문해도된다.
    //미로에서 탈출한 경로를 문자열로 나타낼대 문자열이 사전순으로 가장 빠른 경로로 탈출해야한다.
    
    //위 조건대로 미로를 탈출할 수 없는 경우 "impossible"
    
    return answer;
}