#include <iostream>
using namespace std;
int map[555][555];
int n, k;
void input();
void solve();
int poly(int a, int b);
void except();
int main(){
    input();
    solve();
}
void input(){
    scanf("%d", &n);
    scanf("%d", &k);
    for(int j = 1; j <= n; j++){
        for(int i = 1; i <= k; i++) {
            scanf("%d", &map[j][i]);
        }
    }
}
void solve(){
    int ans = 0;
    for(int j = 1; j <= n; j++){
        for(int i = 1; i <= k; i++) {
            ans = max(ans, poly(j, i));
        }
    }
    printf("%d", ans);
}
int poly(int a, int b){ // 단순히 모든 테트로미노를 체크해본다
    int res = 0;
    if (b + 3 <= k) res = max(res, map[a][b] + map[a][b + 1] + map[a][b + 2] + map[a][b + 3]);
    if (a + 3 <= n) res = max(res, map[a][b] + map[a + 1][b] + map[a + 2][b] + map[a + 3][b]);
    
    if (a + 1 <= n and b + 1 <= k) res = max(res, map[a][b] + map[a][b + 1] + map[a + 1][b] + map[a + 1][b + 1]);
    
    if (a + 2 <= n and b + 1 <= k) res = max(res, map[a][b] + map[a + 1][b] + map[a + 2][b] + map[a][b + 1]);
    if (a + 2 <= n and b - 1 >= 1) res = max(res, map[a][b] + map[a + 1][b] + map[a + 2][b] + map[a][b - 1]);
    if (a - 1 >= 1 and b + 2 <= k) res = max(res, map[a][b] + map[a][b + 1] + map[a][b + 2] + map[a - 1][b]);
    if (a + 1 <= n and b + 2 <= k) res = max(res, map[a][b] + map[a][b + 1] + map[a][b + 2] + map[a + 1][b]);
    if (a - 2 >= 1 and b - 1 >= 1) res = max(res, map[a][b] + map[a - 1][b] + map[a - 2][b] + map[a][b - 1]);
    if (a - 2 >= 1 and b + 1 <= k) res = max(res, map[a][b] + map[a - 1][b] + map[a - 2][b] + map[a][b + 1]);
    if (a + 1 <= n and b - 2 >= 1) res = max(res, map[a][b] + map[a][b - 1] + map[a][b - 2] + map[a + 1][b]);
    if (a - 1 >= 1 and b - 2 >= 1) res = max(res, map[a][b] + map[a][b - 1] + map[a][b - 2] + map[a - 1][b]);
 
    
    if (a - 1 >= 1 and a + 1 <= n and b - 1 >= 1) res = max(res, map[a][b] + map[a - 1][b] + map[a][b - 1] + map[a + 1][b - 1]);
    if (a - 1 >= 1 and a + 1 <= n and b - 1 >= 1) res = max(res, map[a][b] + map[a + 1][b] + map[a][b - 1] + map[a - 1][b - 1]);
    if (a + 1 <= n and b + 1 <= k and b - 1 >= 1) res = max(res, map[a][b] + map[a + 1][b] + map[a][b + 1] + map[a + 1][b - 1]);
    if (a + 1 <= n and b + 1 <= k and b - 1 >= 1) res = max(res, map[a][b] + map[a + 1][b] + map[a][b - 1] + map[a + 1][b + 1]);
    
    if (a - 1 >= 1 and a + 1 <= n and b + 1 <= k) res = max(res, map[a][b] + map[a + 1][b] + map[a - 1][b] + map[a][b + 1]);
    if (a - 1 >= 1 and a + 1 <= n and b - 1 >= 1) res = max(res, map[a][b] + map[a + 1][b] + map[a - 1][b] + map[a][b - 1]);
    if (b - 1 >= 1 and b + 1 <= k and a - 1 >= 1) res = max(res, map[a][b] + map[a - 1][b] + map[a][b + 1] + map[a][b - 1]);
    if (b - 1 >= 1 and b + 1 <= k and a + 1 <= n) res = max(res, map[a][b] + map[a + 1][b] + map[a][b + 1] + map[a][b - 1]);
    
    return res;
}
