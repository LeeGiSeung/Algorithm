#include <iostream>
#include <cmath>
using namespace std;
int n, m;
int bbqx[15]; // 치킨 집의 x 좌표
int bbqy[15]; // 치킨 집의 y 좌표
int hx[2520]; // 집의 x 좌표
int hy[2520]; // 집의 y 좌표 
int permu[15]; // 순열 배열
int idx = 0; // 치킨 집의 개수
int idx2 = 0; // 집의 개수 
int result = 987654321; // 도시의 치킨 거리
 
void combination(int cnt, int next){
    if(cnt == m){ // 순열이 다 찬 경우
        int temp = 0; // 도시의 치킨 거리
        for (int i = 0; i < idx2; i++){
            int mndis = 987654321; // 각 집과 가까운 치킨 집 사이의 거리
            // 도시의 치킨 거리
            for (int j = 0; j < m; j++){
                // 각 집과 가까운 치킨 집 사이의 거리
                 int dis= abs(hx[i] - bbqx[permu[j]]) + abs(hy[i] - bbqy[permu[j]]);
                if(mndis > dis)
                    mndis = dis; // 가장 가까운 치킨집 거리
            }
            temp += mndis;  
        }
        if(result > temp) // 최단의 도시의 치킨 거리일 경우
            result = temp;
    }else{
        // 조합 
        for (int i = next; i < idx; i++){
            permu[cnt] = i;
            combination(cnt + 1, i + 1);
        }
    }
}
 
int main(){
    cin >> n >> m;
    int a;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a;
            if(a == 2){
                bbqx[idx] = i;
                bbqy[idx] = j;
                idx++;
            }
            else if(a == 1){
                hx[idx2] = i;
                hy[idx2] = j;
                idx2++;
            }
        }
    }
    combination(0, 0);
    cout << result << '\n'; 
    return 0;
}