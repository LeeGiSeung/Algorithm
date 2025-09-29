#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solve(int x, int y, int xx, int yy){
    int dx = x - xx;
    int dy = y - yy;
    return dx * dx + dy * dy;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for(int i = 0; i<balls.size(); i++){
        int x = balls[i][0];
        int y = balls[i][1];
        
        //공이 어디로 튀어야 하는지 검사
        
        int minidst = 1e8;
        //공이 같은 직선상에 있으면 그 선에있는 벽은 사용못함
        if(!(x == startX && y > startY)){ //같은 x(가로)에 존재하고 목표 공이 위쪽에 있으면 위쪽벽 x
            minidst = min(minidst, solve(startX, startY, x, 2 * n - y));
        }
        if(!(y == startY && x > startX)){ //같은 x(가로)에 존재하고 목표 공이 위쪽에 있으면 오른쪽 x
            minidst = min(minidst, solve(startX, startY, 2 * m - x, y));
        }
        if(!(x == startX && startY > y)){ //같은 x(가로)에 존재하고 목표 공이 위쪽에 있으면 왼쪽 x
            minidst = min(minidst, solve(startX, startY, x, -y));
        }
        if(!(y == startY && startX > x)){ //같은 x(가로)에 존재하고 목표 공이 위쪽에 있으면 아래 x
            minidst = min(minidst, solve(startX, startY, -x, y));
        }
        
        answer.push_back(minidst);
        
    }
    
    
    
    return answer;
}