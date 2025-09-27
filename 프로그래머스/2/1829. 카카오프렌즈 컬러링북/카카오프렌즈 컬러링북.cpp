#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <string.h>
#include <queue>
using namespace std;

bool check[101][101];
vector<int> answer(2);

struct Data{
    int x;
    int y;
};
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int max_size_of_one_area = 0;

void solve(int i, int j, vector<vector<int>> &picture, int m, int n){
    //areacheck 해당 색깔이 들어왔는지 들어왔으면 true하고 카운트 늘림
    check[i][j] = true;
    int color = picture[i][j];
    int count = 1;
    queue<Data> q;
    q.push({i,j});
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(check[nx][ny]) continue;
            if(picture[nx][ny] != color) continue;
            check[nx][ny] = true;
            //같은 color임
            count++;
            q.push({nx,ny});
        }   
    }
    
    max_size_of_one_area = max(max_size_of_one_area, count);
    return;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    max_size_of_one_area = 0;
    memset(check, false, sizeof(check));

    //36 + 70 + 30 = 136 - 16
    //그림의 난이도를 영역의 수로 정의하였다. (영역이란 상하좌우로 연결된 같은 색상의 공간을 의미한다.)
    
    //number_of_area 그림 내 영역의 갯수
    //max_size_of_one_area 
    
    for(int i = 0; i<picture.size(); i++){
        for(int j = 0; j<picture[i].size(); j++){
            if(picture[i][j] != 0 && !check[i][j]){
                number_of_area++; //새로운 영역 발견한거임
                //cout<<i<<" "<<j<<endl;
                solve(i, j, picture, m, n);
            }
        }
    }
    
    //2^31 - 1 int 최대형
    
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    /*
    [1, 1, 1, 0]
    [1, 2, 2, 0]
    [1, 0, 0, 1]
    [0, 0, 0, 1]
    [0, 0, 0, 3]
    [0, 0, 0, 3]
    */
    
    /*
    [1, 1, 1, 0], 
    [1, 1, 1, 0], 
    [0, 0, 0, 1],
    [0, 0, 0, 1], 
    [0, 0, 0, 1], 
    [0, 0, 0, 1]
    */
    return answer;
}