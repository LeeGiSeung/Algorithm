#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int map[10][10];
vector<pair<int,int>> empties;

// 스도쿠 출력
bool printNumber(){
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++) cout << map[i][j];
        cout << '\n';
    }
    return true;
}

// 가능한 수인가?(중복 체크)
bool isPossible(int x, int y, int k){
    for(int i = 1; i <= 9; i++){
        // 같은 행 체크
        if(map[x][i] == k && i != y) return false;
        // 같은 열 체크
        if(map[i][y] == k && i != x) return false;

        // 같은 3x3 사각형 체크
        int nx = (x-1)/3*3 + 1 +(i-1)/3;
        int ny = (y-1)/3*3 + 1 + (i-1)%3;
        if(map[nx][ny] == k && !(nx == x && ny == y)) return false;
    }
    return true;
}

// 백트래킹 함수
void backTracking(int idx){
    
	// 빈칸을 다 채웠다면(빈칸 배열 끝까지 진행)
    if(idx == empties.size()) {
        printNumber();
        exit(0);
    }


    int x = empties[idx].first;
    int y = empties[idx].second;
    for(int k = 1; k <= 9; k++){
        // k가 가능한 수일때만
        if(isPossible(x,y,k)){
            map[x][y] = k;
            backTracking(idx+1);
            // 다른 수도 사용할 수 있도록 할당 해제
            map[x][y] = 0;
        }
    }
    return;

}
int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    
    for(int i = 1; i <= 9; i++){
        string str;
        cin >> str;
        for(int j = 1; j <= 9; j++) {
            map[i][j] = str[j-1]-'0';
            if(map[i][j] == 0) empties.push_back(make_pair(i,j));
        }
    }
    backTracking(0);

}