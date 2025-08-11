#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>
#include <string.h>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool check[101][101];
struct Data{
    int x;
    int y;
    int time;
};

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int n = maps.size() - 1;
    int m = maps[0].size() - 1;
    memset(check,false,sizeof(check));
    
    queue<Data> q;
    q.push({0,0,0});
    check[0][0] = true;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int time = q.front().time;
        q.pop();
        //cout<<x<<" "<<y<<endl;
        if(x == n && y == m){
            answer = time + 1;
            break;
        }
        else{
            for(int i = 0; i<4; i++){
                int nx = dx[i] + x;
                int ny = dy[i] + y;
                if(nx < 0 || nx > n || ny < 0 || ny > m) continue;
                if(check[nx][ny] == true) continue;
                if(maps[nx][ny] == 0) continue;
                check[nx][ny] = true;
                q.push({nx,ny,time + 1});
            }
        }
    }
    
    return answer;
}