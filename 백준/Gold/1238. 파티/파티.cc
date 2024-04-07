#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define INF 98765432
using namespace std;
int n,x,m;
vector<pair<int, int>> v[1002];
int dst[1002]; // 정점까지의 최단거리를 기록
int result; // 최단거리
 
// 다익스트라
void fc(int a, int d){
    memset(dst, INF, sizeof(dst)); // 초기값 INF
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
 // 우선순위 큐(최소 거리가 루트로)
    pq.push({0, a});// pq(거리, 정점)
    dst[a] = 0; // 시작 지점 거리 0으로 초기화
    while(!pq.empty()){
        int cx = pq.top().second; // 현재 정점
        int cdst = pq.top().first; // 현재 정점까지 거리
        pq.pop();
        if(cx == d){ // 현재 정점에 도착했다면
            result = dst[cx]; // 최단 거리 기록
            break;
        }
        for (int i = 0; i < v[cx].size();i++){ 
            // 현재 정점과 이어진 다음 정점들 
            int nx = v[cx][i].first; // 다음 정점 
            int ndst = v[cx][i].second + cdst; // 다음 정점까지 거리 계산
            if(dst[nx] > ndst){
                 // 다음 정점까지 거리와 기록된 정점까지 거리와 비교해
                 // 최단거리라면
                dst[nx] = ndst; // 최단거리 기록
                pq.push({ndst, nx}); // 큐에 넣어줌
            }
        }
    }
}
int main(){
    cin >> n >> m >> x;
    int ans1, ans2, ans;
    ans = 0;
    int a, b, t;
    for (int i = 0; i < m;i++){
        cin >> a >> b >> t;
        v[a].push_back({b, t});
    }
    for (int i = 1; i <= n;i++){
        fc(i, x); // 가는 길 최단 거리 
        ans1 = result; 
        fc(x, i); // 오는 길 최단 거리
        ans2 = result;
        if(ans < ans1+ans2)
            ans = ans1 + ans2; // 합
    }
    cout << ans << '\n'; // 최단 거리 출력
    return 0;
}
