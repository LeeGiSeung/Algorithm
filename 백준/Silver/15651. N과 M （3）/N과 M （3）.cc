#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[8];

void backtrack(int k){
    if(k==m){
        for(int i=0; i<m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=1; i<=n; i++){
        arr[k] = i;
        backtrack(k+1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    backtrack(0);

    return 0;
}