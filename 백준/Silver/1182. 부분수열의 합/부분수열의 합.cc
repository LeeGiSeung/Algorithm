#include <iostream>
using namespace std;

int n, target, sum, answer;
int arr[20];


//모든 경우의수 : 모든 숫자가 들어가거나 안들어가거나
// 따라서 2의 n승 

// -----dfs도 두가지 경우로 나눈다 ---- 
// 1. 해당 숫자가 들어갈때 : sum += 현재숫자
// 2. 해당 숫자가 안들어갈때 : sum = sum

void dfs(int i, int sum) {

    //모든 수를 다 더하면 리턴
    if (i == n) return;

    //지금까지의 합에서 현재를 더함 > 정답이면 카운트 1
    if (sum + arr[i] == target) answer++;

    //아니면 dfs를 계속 돌린다
    //현재 숫자를 안더하고 (넘어가고) 다음 숫자를 받는 경우
    dfs(i + 1, sum);

    //sum = sum + 현재값
    dfs(i + 1, sum + arr[i]);
}

int main() {

    cin >> n >> target;
    
    for (int i = 0; i < n; i++)cin >> arr[i];

    answer = 0;
    dfs(0, 0);

    cout << answer;

    return 0;
}